#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include<QsoundEffect>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 初始化其他窗口和连接信号与槽
    this->main2 = new MainWindow2;
    connect(main2, &MainWindow2::switch2main, this, &MainWindow::fromw2main);
    this->main3 = new GameOver;
    connect(main3, &GameOver::switch2main, this, &MainWindow::fromw2main);
    this->main4 = new MainWindow3;

    // 从设置中读取玩家坦克的初始属性值
    mTank.HP = settings::readSettings("Hp:").toInt();
    hp = settings::readSettings("Hp:").toInt();
    mTank.mTankSpeed = settings::readSettings("Speed:").toInt();
    mtankspeed = settings::readSettings("Speed:").toInt();
    Fire = settings::readSettings("Fire:").toInt();
    grade = settings::readSettings("Grade:").toInt();
    Death = settings::readSettings("Death:").toInt();
    KillNum = settings::readSettings("KillNum:").toInt();
    accomplishment = settings::readSettings("Accomplishment:").toInt();

    // 设置主窗口大小
    this->setFixedSize(1320, 790);

    // 设置游戏视图和场景的大小和位置
    mGameView.setSceneRect(QRect(0, 0, 1280, 720));
    mScene.setSceneRect(QRect(0, 0, 1280, 720));

    // 设置背景图片并添加到场景中
    mBackGround.setPixmap(QPixmap(":/90Tank/start/8114UVRG{SC5(IMLK}5XH3D.png"));
    mScene.addItem(&mBackGround);

    // 将玩家坦克添加到场景中
    mScene.addItem(&mTank);

    // 将游戏视图设置为主窗口的中央部件
    mGameView.setScene(&mScene);
    mGameView.setParent(this);
    setCentralWidget(&mGameView);
    mGameView.show();

    // 初始化游戏中的各种功能和碰撞检测
    EnemyBoom();
    EnemyMove();
    BossShoot();
    BossMove();
    BossBoom();
    BossCollide();
    myTankCollide1();
    myTankCollide2();
    myTankCollide3();
    BuildingCollide1();
    BuildingCollide2();
    BuildingCollide3();
    BuildingCollide4();
    eBulletShoot();
    bBulletShoot();

    // 初始化子弹移动计时器，并连接其超时信号到对应槽函数
    BulletTime = new QTimer(this);
    BulletTime->start(50);
    connect(BulletTime, &QTimer::timeout, [this]() {
        for (auto bullet : mBullet) {
            bullet->BulletMove();
        }
    });

    // 初始化游戏定时器，用于控制游戏结束条件
    Time = new QTimer(this);
    Time->start(100);
    connect(Time, &QTimer::timeout, this, &MainWindow::gameOver);

    // 初始化子弹发射计时器，根据火力频率调整发射速度
    Time2 = new QTimer(this);
    Time2->start(Fire);
    connect(Time2, &QTimer::timeout, this, &MainWindow::BulletShoot2);

    // 连接游戏结束窗口的重试信号，重新启动游戏
    connect(main3, &GameOver::retry, [=]() {
        this->main3->close();
        Time2->stop();
        QProcess::startDetached(qApp->applicationFilePath(), QStringList());
    });

    // 定时保存游戏进度到设置文件
    Time = new QTimer(this);
    Time->start(100);
    connect(Time, &QTimer::timeout, [this]() {
        QString g = QString::number(grade);
        settings::modifySettings("Grade:", g);
        QString k = QString::number(KillNum);
        settings::modifySettings("KillNum:", k);
        QString d = QString::number(Death);
        settings::modifySettings("Death:", d);
        settings::modifySettings("Accomplishment:", QString::number(accomplishment));
    });
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    // 设置坦克变换的原点为其边界框的中心点
    mTank.setTransformOriginPoint(mTank.boundingRect().center());

    // 根据按键处理坦克的移动和旋转
    switch(event->key()) {
    case Qt::Key_W:
        // 向上移动
        mTank.setRotation(0);
        mTank.moveBy(0, -mTank.mTankSpeed);
        break;
    case Qt::Key_S:
        // 向下移动
        mTank.setRotation(180);
        mTank.moveBy(0, +mTank.mTankSpeed);
        break;
    case Qt::Key_A:
        // 向左移动
        mTank.setRotation(270);
        mTank.moveBy(-mTank.mTankSpeed, 0);
        break;
    case Qt::Key_D:
        // 向右移动
        mTank.setRotation(90);
        mTank.moveBy(+mTank.mTankSpeed, 0);
        break;
    case Qt::Key_J:
        // 按下 J 键，添加到子弹移动列表
        BulletMove.append(Qt::Key_J);
        break;
    case Qt::Key_K:
        // 按下 K 键，修改设置文件中的属性值
        settings::modifySettings("a:", "123");
        break;
    };

    // 碰撞检测，防止坦克移出游戏边界
    if (mTank.x() < 0) {
        mTank.setX(0);
    }
    if (mTank.y() < 0) {
        mTank.setY(0);
    }
    if ((mTank.x() + mTank.pixmap().width()) > 1280) {
        mTank.setX(1280 - mTank.pixmap().width());
    }
    if (mTank.y() + mTank.pixmap().height() > 720) {
        mTank.setY(720 - mTank.pixmap().height());
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    // 处理按键释放事件
    switch(event->key()) {
    case Qt::Key_J:
        // 释放 J 键，从子弹移动列表中移除
        BulletMove.removeAll(Qt::Key_J);
        break;
    }
}

void MainWindow::BulletShoot() {
    // 创建子弹的图像
    QPixmap bulletImg("://90Tank/player_tank/girls_preview.png");

    // 根据坦克的旋转角度确定子弹的初始位置和方向
    if (mTank.rotation() == 0) {
        QPoint pos(mTank.x() + mTank.pixmap().width() / 2, mTank.y());
        Bullet* bullet = new Bullet(pos, bulletImg, 'N'); // 创建北向子弹对象
        bullet->setRotation(0);
        mScene.addItem(bullet); // 将子弹添加到场景中
        mBullet.append(bullet); // 将子弹对象添加到子弹列表中
    }

    if (mTank.rotation() == 180) {
        QPoint pos(mTank.x() + mTank.pixmap().width() / 2, mTank.y() + mTank.pixmap().height());
        Bullet* bullet = new Bullet(pos, bulletImg, 'S'); // 创建南向子弹对象
        bullet->setRotation(180);
        mScene.addItem(bullet);
        mBullet.append(bullet);
    }

    if (mTank.rotation() == 90) {
        QPoint pos(mTank.x() + mTank.pixmap().width(), mTank.y() + mTank.pixmap().height() / 2);
        Bullet* bullet = new Bullet(pos, bulletImg, 'E'); // 创建东向子弹对象
        bullet->setRotation(90);
        mScene.addItem(bullet);
        mBullet.append(bullet);
    }

    if (mTank.rotation() == 270) {
        QPoint pos(mTank.x(), mTank.y() + mTank.pixmap().height() / 2);
        Bullet* bullet = new Bullet(pos, bulletImg, 'W'); // 创建西向子弹对象
        bullet->setRotation(270);
        mScene.addItem(bullet);
        mBullet.append(bullet);
    }
}

void MainWindow::BulletShoot2() {
    // 遍历当前按下的所有键码
    for (int keyCode : BulletMove) {
        if (keyCode == Qt::Key_J) {
            BulletShoot(); // 按下 J 键时，触发玩家坦克射击子弹
        }
    }
}

void MainWindow::EnemyShoot() {
    // 创建敌方子弹的图像
    QPixmap ebulletImg("://90Tank/enemy/pic_13step.png");

    // 遍历所有敌方坦克
    for (auto enemy : mEnemy) {
        // 根据敌方坦克的旋转角度确定子弹的初始位置和方向
        if (enemy->rotation() == 0) {
            QPoint pos(enemy->x() + enemy->pixmap().width() / 2, enemy->y());
            enemyBullet* ebullet = new enemyBullet(pos, ebulletImg, 'N'); // 创建北向敌方子弹对象
            ebullet->setRotation(0);
            mScene.addItem(ebullet);
            eBullet.append(ebullet);
        }

        if (enemy->rotation() == 180) {
            QPoint pos(enemy->x() + enemy->pixmap().width() / 2, enemy->y() + enemy->pixmap().height());
            enemyBullet* ebullet = new enemyBullet(pos, ebulletImg, 'S'); // 创建南向敌方子弹对象
            ebullet->setRotation(180);
            mScene.addItem(ebullet);
            eBullet.append(ebullet);
        }

        if (enemy->rotation() == 90) {
            QPoint pos(enemy->x() + enemy->pixmap().width(), enemy->y() + enemy->pixmap().height() / 2);
            enemyBullet* ebullet = new enemyBullet(pos, ebulletImg, 'E'); // 创建东向敌方子弹对象
            ebullet->setRotation(90);
            mScene.addItem(ebullet);
            eBullet.append(ebullet);
        }

        if (enemy->rotation() == 270) {
            QPoint pos(enemy->x(), enemy->y() + enemy->pixmap().height() / 2);
            enemyBullet* ebullet = new enemyBullet(pos, ebulletImg, 'W'); // 创建西向敌方子弹对象
            ebullet->setRotation(270);
            mScene.addItem(ebullet);
            eBullet.append(ebullet);
        }
    }
}

void MainWindow::BossShoot() {
    // 加载boss子弹的图像
    QPixmap ebulletImg("://90Tank/enemy/animation_sprite_125.png");

    // 遍历所有boss坦克
    for (auto enemy : mBoss) {
        // 根据boss坦克的旋转角度确定四个方向的初始位置
        if (enemy->rotation() == 0) {
            QPoint pos(enemy->x() + enemy->pixmap().width() / 2 + 10, enemy->y());
            QPoint pos2(enemy->x() + enemy->pixmap().width() / 2 - 20, enemy->y());
            QPoint pos3(enemy->x() + 30, enemy->y());
            QPoint pos4(enemy->x() + enemy->pixmap().width() - 30, enemy->y());
            BossBullet* ebullet = new BossBullet(pos, ebulletImg, 'N'); // 创建北向boss子弹对象
            BossBullet* ebullet2 = new BossBullet(pos2, ebulletImg, 'N');
            BossBullet* ebullet3 = new BossBullet(pos3, ebulletImg, 'N');
            BossBullet* ebullet4 = new BossBullet(pos4, ebulletImg, 'N');
            ebullet->setRotation(0);
            ebullet2->setRotation(0);
            ebullet3->setRotation(0);
            ebullet4->setRotation(0);
            mScene.addItem(ebullet); // 将子弹添加到场景中
            mScene.addItem(ebullet2);
            mScene.addItem(ebullet3);
            mScene.addItem(ebullet4);
            bBullet.append(ebullet); // 将子弹对象添加到boss子弹列表中
            bBullet.append(ebullet2);
            bBullet.append(ebullet3);
            bBullet.append(ebullet4);
        }

        if (enemy->rotation() == 180) {
            QPoint pos(enemy->x() + enemy->pixmap().width() / 2 + 10, enemy->y() + enemy->pixmap().height());
            QPoint pos2(enemy->x() + enemy->pixmap().width() / 2 - 20, enemy->y() + enemy->pixmap().height());
            QPoint pos3(enemy->x() + 30, enemy->y() + enemy->pixmap().height());
            QPoint pos4(enemy->x() + enemy->pixmap().width() - 30, enemy->y() + enemy->pixmap().height());
            BossBullet* ebullet = new BossBullet(pos, ebulletImg, 'S'); // 创建南向boss子弹对象
            BossBullet* ebullet2 = new BossBullet(pos2, ebulletImg, 'S');
            BossBullet* ebullet3 = new BossBullet(pos3, ebulletImg, 'S');
            BossBullet* ebullet4 = new BossBullet(pos4, ebulletImg, 'S');
            ebullet->setRotation(180);
            ebullet2->setRotation(180);
            ebullet3->setRotation(180);
            ebullet4->setRotation(180);
            mScene.addItem(ebullet);
            mScene.addItem(ebullet2);
            mScene.addItem(ebullet3);
            mScene.addItem(ebullet4);
            bBullet.append(ebullet);
            bBullet.append(ebullet2);
            bBullet.append(ebullet3);
            bBullet.append(ebullet4);
        }

        if (enemy->rotation() == 90) {
            QPoint pos(enemy->x() + enemy->pixmap().width(), enemy->y() + enemy->pixmap().height() / 2 + 10);
            QPoint pos2(enemy->x() + enemy->pixmap().width(), enemy->y() + enemy->pixmap().height() / 2 - 20);
            QPoint pos3(enemy->x() + enemy->pixmap().width(), enemy->y() + 30);
            QPoint pos4(enemy->x() + enemy->pixmap().width(), enemy->y() + enemy->pixmap().height() - 30);
            BossBullet* ebullet = new BossBullet(pos, ebulletImg, 'E'); // 创建东向boss子弹对象
            BossBullet* ebullet2 = new BossBullet(pos2, ebulletImg, 'E');
            BossBullet* ebullet3 = new BossBullet(pos3, ebulletImg, 'E');
            BossBullet* ebullet4 = new BossBullet(pos4, ebulletImg, 'E');
            ebullet->setRotation(90);
            ebullet2->setRotation(90);
            ebullet3->setRotation(90);
            ebullet4->setRotation(90);
            mScene.addItem(ebullet);
            mScene.addItem(ebullet2);
            mScene.addItem(ebullet3);
            mScene.addItem(ebullet4);
            bBullet.append(ebullet);
            bBullet.append(ebullet2);
            bBullet.append(ebullet3);
            bBullet.append(ebullet4);
        }

        if (enemy->rotation() == 270) {
            QPoint pos(enemy->x(), enemy->y() + enemy->pixmap().height() / 2 + 10);
            QPoint pos2(enemy->x(), enemy->y() + enemy->pixmap().height() / 2 - 20);
            QPoint pos3(enemy->x(), enemy->y() + 30);
            QPoint pos4(enemy->x(), enemy->y() + enemy->pixmap().height() - 30);
            BossBullet* ebullet = new BossBullet(pos, ebulletImg, 'W'); // 创建西向boss子弹对象
            BossBullet* ebullet2 = new BossBullet(pos2, ebulletImg, 'W');
            BossBullet* ebullet3 = new BossBullet(pos3, ebulletImg, 'W');
            BossBullet* ebullet4 = new BossBullet(pos4, ebulletImg, 'W');
            ebullet->setRotation(270);
            ebullet2->setRotation(270);
            ebullet3->setRotation(270);
            ebullet4->setRotation(270);
            mScene.addItem(ebullet);
            mScene.addItem(ebullet2);
            mScene.addItem(ebullet3);
            mScene.addItem(ebullet4);
            bBullet.append(ebullet);
            bBullet.append(ebullet2);
            bBullet.append(ebullet3);
            bBullet.append(ebullet4);
        }
    }
}

void MainWindow::eBulletShoot() {
    Time = new QTimer(this);
    Time->start(2000);
    connect(Time, &QTimer::timeout, [this]() {
        EnemyShoot(); // 每隔一段时间触发敌方坦克射击子弹
    });
    EnemyShoot(); // 初始时立即触发一次敌方坦克射击子弹
    Time2 = new QTimer(this);
    Time2->start(50);
    connect(Time2, &QTimer::timeout, [this]() {
        for (auto bullet : eBullet) {
            bullet->eBulletMove(); // 每隔一小段时间更新敌方子弹的位置
        }
    });
}

void MainWindow::bBulletShoot() {
    Time = new QTimer(this);
    Time->start(1000);
    connect(Time, &QTimer::timeout, [this]() {
        BossShoot(); // 每隔一段时间触发boss射击子弹
    });
    BossShoot(); // 初始时立即触发一次boss射击子弹
    Time2 = new QTimer(this);
    Time2->start(50);
    connect(Time2, &QTimer::timeout, [this]() {
        for (auto bullet : bBullet) {
            bullet->BossBulletMove(); // 每隔一小段时间更新boss子弹的位置
        }
    });
}

void MainWindow::CreatEnemy(int x, int y)
{
    // 创建一个敌方坦克对象，并设置初始位置和初始生命值
    Enemy* enemy = new Enemy(x, y, Ehp);
    
    // 将敌方坦克添加到场景中显示
    mScene.addItem(enemy);
    
    // 将敌方坦克对象添加到敌方坦克列表中管理
    mEnemy.append(enemy);
}

void MainWindow::CreatBoss(int x, int y)
{
    // 创建一个Boss坦克对象，并设置初始位置
    BOSS* boss = new BOSS(x, y);
    
    // 将Boss坦克添加到场景中显示
    mScene.addItem(boss);
    
    // 将Boss坦克对象添加到Boss列表中管理
    mBoss.append(boss);
}

void MainWindow::EnemyBoom()
{
    // 创建定时器，每隔10毫秒触发一次
    Time = new QTimer(this);
    Time->start(10);
    
    // 连接定时器的timeout信号到lambda表达式
    connect(Time, &QTimer::timeout, [this]() {
        // 遍历敌方坦克列表
        for (auto enemy : mEnemy) {
            // 遍历子弹列表
            for (auto bullet : mBullet) {
                // 如果子弹与敌方坦克碰撞
                if (bullet->collidesWithItem(enemy)) {
                    // 从子弹列表中移除子弹，并释放内存
                    mBullet.removeOne(bullet);
                    bullet->deleteLater();
                    
                    // 减少敌方坦克生命值
                    enemy->EHP--;
                    
                    // 如果敌方坦克生命值小于等于0
                    if (enemy->EHP <= 0) {
                        // 从敌方坦克列表中移除敌方坦克
                        mEnemy.removeOne(enemy);
                        
                        // 设置爆炸效果动画
                        enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite.png"));
                        QTimer::singleShot(50, this, [=]() {
                            enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite2.png"));
                        });
                        QTimer::singleShot(100, this, [=]() {
                            enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite3.png"));
                        });
                        QTimer::singleShot(150, this, [=]() {
                            enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite4.png"));
                        });
                        QTimer::singleShot(200, this, [=]() {
                            enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite5.png"));
                            enemy->deleteLater(); // 删除敌方坦克对象并释放内存
                        });
                        
                        // 增加击杀计数和总击杀数
                        killnum++;
                        KillNum++;
                        
                        // 增加分数
                        grade += 100;
                    }
                }
            }
        }
    });
}

void MainWindow::BossBoom()
{
    // 创建定时器，每隔10毫秒触发一次
    Time = new QTimer(this);
    Time->start(10);
    
    // 连接定时器的timeout信号到lambda表达式
    connect(Time, &QTimer::timeout, [this]() {
        // 遍历Boss坦克列表
        for (auto enemy : mBoss) {
            // 遍历子弹列表
            for (auto bullet : mBullet) {
                // 如果子弹与Boss坦克碰撞
                if (bullet->collidesWithItem(enemy)) {
                    // 从子弹列表中移除子弹，并释放内存
                    mBullet.removeOne(bullet);
                    bullet->deleteLater();
                    
                    // 减少Boss坦克生命值
                    enemy->BossHp--;
                    
                    // 如果Boss坦克生命值小于等于0
                    if (enemy->BossHp <= 0) {
                        // 从Boss坦克列表中移除Boss坦克
                        mBoss.removeOne(enemy);
                        
                        // 设置爆炸效果动画
                        enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite.png"));
                        QTimer::singleShot(50, this, [=]() {
                            enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite2.png"));
                        });
                        QTimer::singleShot(100, this, [=]() {
                            enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite3.png"));
                        });
                        QTimer::singleShot(150, this, [=]() {
                            enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite4.png"));
                        });
                        QTimer::singleShot(200, this, [=]() {
                            enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite5.png"));
                            enemy->deleteLater(); // 删除Boss坦克对象并释放内存
                        });
                        
                        // 增加击杀计数和总击杀数
                        killnum++;
                        KillNum += 50;
                        
                        // 增加分数
                        grade += 10000;
                    }
                }
            }
        }
    });
}
void MainWindow::EnemyMove()
{
    // 创建定时器，每隔1秒触发一次，用于更新敌方坦克移动方向
    Time2 = new QTimer(this);
    Time2->start(1000);
    connect(Time2, &QTimer::timeout, [this]() {
        // 随机生成一个移动方向
        dir = rand();
    });
    
    // 创建定时器，每隔0.1秒触发一次，用于实现敌方坦克的移动
    Time = new QTimer(this);
    Time->start(100);
    connect(Time, &QTimer::timeout, [this]() {
        // 遍历所有敌方坦克
        for (auto enemy : mEnemy) {
            enemy->setTransformOriginPoint(enemy->boundingRect().center());
            
            // 根据随机生成的方向决定敌方坦克的移动行为
            if (dir % 2 == 1) { // 方向为奇数时
                if (mTank.x() > enemy->x()) { // 坦克在敌方坦克右侧时
                    enemy->setRotation(90); // 设置朝向右侧
                    enemy->moveBy(enemy->enemySpeed, 0); // 向右移动
                }
                if (mTank.x() < enemy->x()) { // 坦克在敌方坦克左侧时
                    enemy->setRotation(270); // 设置朝向左侧
                    enemy->moveBy(-enemy->enemySpeed, 0); // 向左移动
                }
            }
            if (dir % 2 == 0) { // 方向为偶数时
                if (mTank.y() < enemy->y()) { // 坦克在敌方坦克上方时
                    enemy->setRotation(0); // 设置朝向上方
                    enemy->moveBy(0, -enemy->enemySpeed); // 向上移动
                }
                if (mTank.y() > enemy->y()) { // 坦克在敌方坦克下方时
                    enemy->setRotation(180); // 设置朝向下方
                    enemy->moveBy(0, enemy->enemySpeed); // 向下移动
                }
            }
        }
    });
}

void MainWindow::BossMove()
{
    // 创建定时器，每隔1秒触发一次，用于更新Boss坦克移动方向
    Time2 = new QTimer(this);
    Time2->start(1000);
    connect(Time2, &QTimer::timeout, [this]() {
        // 随机生成一个移动方向
        dir = rand();
    });
    
    // 创建定时器，每隔0.1秒触发一次，用于实现Boss坦克的移动
    Time = new QTimer(this);
    Time->start(100);
    connect(Time, &QTimer::timeout, [this]() {
        // 遍历所有Boss坦克
        for (auto enemy : mBoss) {
            enemy->setTransformOriginPoint(enemy->boundingRect().center());
            
            // 根据随机生成的方向决定Boss坦克的移动行为
            if (dir % 2 == 1) { // 方向为奇数时
                if (mTank.x() > enemy->x()) { // 坦克在Boss坦克右侧时
                    enemy->setRotation(90); // 设置朝向右侧
                    enemy->moveBy(enemy->bossSpeed, 0); // 向右移动
                }
                if (mTank.x() < enemy->x()) { // 坦克在Boss坦克左侧时
                    enemy->setRotation(270); // 设置朝向左侧
                    enemy->moveBy(-enemy->bossSpeed, 0); // 向左移动
                }
            }
            if (dir % 2 == 0) { // 方向为偶数时
                if (mTank.y() < enemy->y()) { // 坦克在Boss坦克上方时
                    enemy->setRotation(0); // 设置朝向上方
                    enemy->moveBy(0, -enemy->bossSpeed); // 向上移动
                }
                if (mTank.y() > enemy->y()) { // 坦克在Boss坦克下方时
                    enemy->setRotation(180); // 设置朝向下方
                    enemy->moveBy(0, enemy->bossSpeed); // 向下移动
                }
            }
        }
    });
}

void MainWindow::myTankCollide1()
{
    Death++; // 记录死亡次数加一
    Time = new QTimer(this);
    Time->start(10);
    connect(Time, &QTimer::timeout, [this]() {
        // 检测主坦克与敌方坦克的碰撞
        for (auto enemy : mEnemy) {
            if (mTank.collidesWithItem(enemy)) { // 如果主坦克与敌方坦克碰撞
                mEnemy.removeOne(enemy); // 移除敌方坦克
                emit boomEffect(); // 发送爆炸效果信号

                // 设置敌方坦克爆炸动画
                enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite.png"));
                QTimer::singleShot(50, this, [=]() {
                    enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite2.png"));
                });
                QTimer::singleShot(100, this, [=]() {
                    enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite3.png"));
                });
                QTimer::singleShot(150, this, [=]() {
                    enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite4.png"));
                });
                QTimer::singleShot(200, this, [=]() {
                    enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite5.png"));
                });
                QTimer::singleShot(200, this, [=]() {
                    enemy->deleteLater(); // 延时删除敌方坦克对象
                });

                // 停止主坦克的移动，并设置爆炸动画
                mTank.mTankSpeed = 0;
                mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite.png"));
                QTimer::singleShot(50, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite2.png"));
                });
                QTimer::singleShot(100, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite3.png"));
                });
                QTimer::singleShot(150, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite4.png"));
                });
                QTimer::singleShot(200, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite5.png"));
                });

                // 重新设置主坦克的位置、速度，并处理子弹
                QTimer::singleShot(250, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/player_tank/mTank.png"));
                    mTank.setX(200);
                    mTank.setY(200);
                    mTank.mTankSpeed = mtankspeed;
                    for (auto bullet : mBullet) {
                        mBullet.removeOne(bullet);
                        bullet->deleteLater();
                    }
                    mTank.HP--; // 主坦克生命值减一
                    showHeart(mTank.HP); // 更新显示生命值的心形图标
                });

                killnum++; // 击杀数加一
                grade += 100; // 分数增加100分
            }
        }
    });
}

void MainWindow::myTankCollide2()
{
    Death++; // 记录死亡次数加一
    Time = new QTimer(this);
    Time->start(10);
    connect(Time, &QTimer::timeout, [this]() {
        // 检测主坦克与敌方子弹的碰撞
        for (auto bullet : eBullet) {
            if (bullet->collidesWithItem(&mTank)) { // 如果敌方子弹与主坦克碰撞
                eBullet.removeOne(bullet); // 移除敌方子弹
                bullet->deleteLater(); // 延时删除子弹对象
                mTank.mTankSpeed = 0; // 停止主坦克的移动
                emit boomEffect(); // 发送爆炸效果信号

                // 设置主坦克爆炸动画
                mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite.png"));
                QTimer::singleShot(50, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite2.png"));
                });
                QTimer::singleShot(100, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite3.png"));
                });
                QTimer::singleShot(150, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite4.png"));
                });
                QTimer::singleShot(200, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite5.png"));
                });

                // 重新设置主坦克的位置、速度，并处理子弹
                QTimer::singleShot(250, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/player_tank/mTank.png"));
                    mTank.setX(200);
                    mTank.setY(200);
                    mTank.mTankSpeed = mtankspeed;
                    for (auto bullet : mBullet) {
                        mBullet.removeOne(bullet);
                        bullet->deleteLater();
                    }
                    mTank.HP--; // 主坦克生命值减一
                    showHeart(mTank.HP); // 更新显示生命值的心形图标
                });
            }
        }
    });
}

void MainWindow::myTankCollide3()
{
    Time = new QTimer(this);
    Time->start(10);
    connect(Time, &QTimer::timeout, [this]() {
        // 检测主坦克与Boss子弹的碰撞
        for (auto bullet : bBullet) {
            if (bullet->collidesWithItem(&mTank)) { // 如果Boss子弹与主坦克碰撞
                bBullet.removeOne(bullet); // 移除Boss子弹
                bullet->deleteLater(); // 延时删除子弹对象
                mTank.mTankSpeed = 0; // 停止主坦克的移动
                emit boomEffect(); // 发送爆炸效果信号

                // 设置主坦克爆炸动画
                mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite.png"));
                QTimer::singleShot(50, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite2.png"));
                });
                QTimer::singleShot(100, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite3.png"));
                });
                QTimer::singleShot(150, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite4.png"));
                });
                QTimer::singleShot(200, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite5.png"));
                });

                // 重新设置主坦克的位置、速度，并处理子弹
                QTimer::singleShot(250, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/player_tank/mTank.png"));
                    mTank.setX(200);
                    mTank.setY(200);
                    mTank.mTankSpeed = mtankspeed;
                    for (auto bullet : mBullet) {
                        mBullet.removeOne(bullet);
                        bullet->deleteLater();
                    }
                    mTank.HP--; // 主坦克生命值减一
                    showHeart(mTank.HP); // 更新显示生命值的心形图标
                });
            }
        }
    });
}

void MainWindow::BuildingCreate(int y, int x, int kind)
{
    Building* building = new Building(y, x, kind); // 创建建筑物对象
    mScene.addItem(building); // 在场景中添加建筑物
    mBuilding.append(building); // 将建筑物对象添加到列表中
}

void MainWindow::BossCollide()
{
    Time = new QTimer(this); // 创建定时器对象
    Time->start(10); // 启动定时器，每10毫秒触发一次
    connect(Time, &QTimer::timeout, [this]() {
        // 检测主坦克与Boss的碰撞
        for (auto enemy : mBoss) {
            if (mTank.collidesWithItem(enemy)) { // 如果主坦克与Boss碰撞
                mTank.mTankSpeed = 0; // 停止主坦克的移动
                emit boomEffect(); // 发送爆炸效果信号

                // 设置主坦克爆炸动画
                mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite.png"));
                QTimer::singleShot(50, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite2.png"));
                });
                QTimer::singleShot(100, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite3.png"));
                });
                QTimer::singleShot(150, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite4.png"));
                });
                QTimer::singleShot(200, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite5.png"));
                });

                // 延时一段时间后重置主坦克的状态
                QTimer::singleShot(250, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/player_tank/mTank.png")); // 恢复主坦克正常状态
                    mTank.setX(200); // 重置主坦克的X坐标
                    mTank.setY(200); // 重置主坦克的Y坐标
                    mTank.mTankSpeed = mtankspeed; // 恢复主坦克的移动速度
                    mTank.HP--; // 减少主坦克的生命值
                    showHeart(mTank.HP); // 更新显示主坦克生命值的UI
                });
            }
        }
    });
}

void MainWindow::BuildingCollide1()
{
    Time = new QTimer(this); // 创建定时器对象
    Time->start(10); // 启动定时器，每10毫秒触发一次
    connect(Time, &QTimer::timeout, [this]() {
        // 检测建筑物与子弹的碰撞
        for (auto building : mBuilding) {
            for (auto bullet : mBullet) {
                if (building->collidesWithItem(bullet)) { // 如果建筑物与子弹碰撞
                    if (building->kind == 1) { // 如果是类型1的建筑物
                        mBullet.removeOne(bullet); // 移除子弹
                        bullet->deleteLater(); // 延时删除子弹对象
                        mBuilding.removeOne(building); // 移除建筑物
                        building->deleteLater(); // 延时删除建筑物对象
                    } else if (building->kind == 2) { // 如果是类型2的建筑物
                        mBullet.removeOne(bullet); // 移除子弹
                        bullet->deleteLater(); // 延时删除子弹对象
                    } else if (building->kind == 3) { // 如果是类型3的建筑物
                        mScene.removeItem(building); // 从场景中移除建筑物
                        mScene.addItem(building); // 将建筑物重新添加到场景
                    }
                }
            }
        }
    });
}
void MainWindow::BuildingCollide2()
{
    Time = new QTimer(this); // 创建定时器对象
    Time->start(1); // 启动定时器，每1毫秒触发一次
    connect(Time, &QTimer::timeout, [this]() {
        // 检测主坦克与建筑物的碰撞
        for (auto building : mBuilding) {
            if (mTank.collidesWithItem(building)) { // 如果主坦克与建筑物碰撞
                if (building->kind != 3) { // 如果建筑物不是类型3（不可穿越的建筑物）
                    // 根据主坦克的旋转角度调整主坦克的位置
                    if (mTank.rotation() == 0) { // 主坦克朝上
                        mTank.setY(building->y() + building->pixmap().height()); // 设置主坦克的Y坐标
                        mTank.setX(mTank.x()); // 设置主坦克的X坐标
                    } else if (mTank.rotation() == 180) { // 主坦克朝下
                        mTank.setY(building->y() - mTank.pixmap().height());
                        mTank.setX(mTank.x());
                    } else if (mTank.rotation() == 90) { // 主坦克朝右
                        mTank.setY(mTank.y());
                        mTank.setX(building->x() - mTank.pixmap().width());
                    } else if (mTank.rotation() == 270) { // 主坦克朝左
                        mTank.setY(mTank.y());
                        mTank.setX(building->x() + building->pixmap().width());
                    }
                }
            }
        }
    });
}

void MainWindow::BuildingCollide3()
{
    Time = new QTimer(this); // 创建定时器对象
    Time->start(1); // 启动定时器，每1毫秒触发一次
    connect(Time, &QTimer::timeout, [this]() {
        // 检测敌方坦克与建筑物的碰撞
        for (auto building : mBuilding) {
            for (auto enemy : mEnemy) {
                if (enemy->collidesWithItem(building)) { // 如果敌方坦克与建筑物碰撞
                    if (building->kind != 3) { // 如果建筑物不是类型3（不可穿越的建筑物）
                        // 根据敌方坦克的旋转角度调整敌方坦克的位置
                        if (enemy->rotation() == 0) { // 敌方坦克朝上
                            enemy->setY(building->y() + building->pixmap().height());
                            enemy->setX(enemy->x());
                        } else if (enemy->rotation() == 180) { // 敌方坦克朝下
                            enemy->setY(building->y() - enemy->pixmap().height());
                            enemy->setX(enemy->x());
                        } else if (enemy->rotation() == 90) { // 敌方坦克朝右
                            enemy->setY(enemy->y());
                            enemy->setX(building->x() - enemy->pixmap().width());
                        } else if (enemy->rotation() == 270) { // 敌方坦克朝左
                            enemy->setY(enemy->y());
                            enemy->setX(building->x() + building->pixmap().width());
                        }
                    }

                    // 如果建筑物是类型3，刷新显示（重新添加到场景）
                    if (building->kind == 3) {
                        mScene.removeItem(building);
                        mScene.addItem(building);
                    }

                    // 确保敌方坦克不会超出场景边界
                    if (enemy->x() < 0) {
                        enemy->setX(0);
                    }
                    if (enemy->y() < 0) {
                        enemy->setY(0);
                    }
                    if (enemy->x() + enemy->pixmap().width() > 1280) {
                        enemy->setX(1280 - enemy->pixmap().width());
                    }
                    if (enemy->y() + enemy->pixmap().height() > 720) {
                        enemy->setY(720 - enemy->pixmap().height());
                    }
                }
            }
        }
    });
}

void MainWindow::BuildingCollide4()
{
    Time = new QTimer(this); // 创建定时器对象
    Time->start(10); // 启动定时器，每10毫秒触发一次
    connect(Time, &QTimer::timeout, [this]() {
        // 检测建筑物与敌方子弹的碰撞
        for (auto building : mBuilding) {
            for (auto bullet : eBullet) {
                if (building->collidesWithItem(bullet)) { // 如果建筑物与敌方子弹碰撞
                    if (building->kind == 1) { // 如果是类型1的建筑物
                        eBullet.removeOne(bullet); // 移除敌方子弹
                        bullet->deleteLater(); // 延时删除子弹对象
                        mBuilding.removeOne(building); // 移除建筑物
                        building->deleteLater(); // 延时删除建筑物对象
                    } else if (building->kind == 2) { // 如果是类型2的建筑物
                        eBullet.removeOne(bullet); // 移除敌方子弹
                        bullet->deleteLater(); // 延时删除子弹对象
                    } else if (building->kind == 3) { // 如果是类型3的建筑物
                        mScene.removeItem(building); // 从场景中移除建筑物
                        mScene.addItem(building); // 将建筑物重新添加到场景
                    }
                }
            }
        }
    });
}

void MainWindow::showHeart(int number)
{
    // 显示心型图标，数量为参数number
    for (int i = 0; i < number; i++) {
        Heart *h = new Heart(0, i); // 创建心型图标对象
        mScene.addItem(h); // 将心型图标添加到场景中
        mHeart.append(h); // 将心型图标对象存入成员变量列表
    }
}

void MainWindow::clear()
{
    // 清理游戏中的所有元素
    for (auto building : mBuilding) {
        mBuilding.removeOne(building); // 从建筑物列表中移除当前建筑物
        building->deleteLater(); // 延时删除建筑物对象
    }
    for (auto enemy : mEnemy) {
        mEnemy.removeOne(enemy); // 从敌方坦克列表中移除当前敌方坦克
        enemy->deleteLater(); // 延时删除敌方坦克对象
    }
    for (auto bullet : mBullet) {
        mBullet.removeOne(bullet); // 从子弹列表中移除当前子弹
        bullet->deleteLater(); // 延时删除子弹对象
    }
}

void MainWindow::game1()
{
    QTimer::singleShot(100, this, [this]{ emit changeMusic(1); }); // 发送改变音乐信号，延时100毫秒执行
    clear(); // 清理游戏场景中的所有元素
    mTank.setX(560); // 设置主坦克的X坐标
    mTank.setY(400); // 设置主坦克的Y坐标

    // 创建围墙
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, -2, 2); // 创建左边的围墙
    }
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, 33, 2); // 创建右边的围墙
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(-1, i, 2); // 创建上边的围墙
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(18, i, 2); // 创建下边的围墙
    }

    // 根据地图数组map1创建具体的建筑物
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 18; j++) {
            if (map1[j][i] != 0) {
                BuildingCreate(j, i, map1[j][i]); // 根据地图数组创建指定类型的建筑物
            }
        }
    }

    mTank.HP = hp; // 设置主坦克的生命值为初始生命值
    showHeart(mTank.HP); // 显示与主坦克生命值对应数量的心型图标
    killnum = 0; // 击败敌人数量重置为0

    // 定时创建敌方坦克
    for (int i = 1; i <= 5; i++) {
        QTimer::singleShot(5000 * i, this, [=]() {
            CreatEnemy(200, 600); // 在指定位置创建敌方坦克
        });
        QTimer::singleShot(10000 * i, this, [=]() {
            CreatEnemy(1100, 600); // 在指定位置创建敌方坦克
        });
    }

    GTime1 = new QTimer(this); // 创建游戏定时器对象
    GTime1->start(100); // 启动定时器，每100毫秒触发一次
    connect(GTime1, &QTimer::timeout, [this]() {
        if (killnum >= 10) { // 如果击败敌人数量达到10个
            killnum = 0; // 重置击败敌人数量
            if (mTank.HP == hp) { // 如果主坦克的生命值与初始生命值相同
                Ehp++; // 敌方坦克的生命值增加
            }
            accomplishment++; // 完成数增加
            GTime1->stop(); // 停止游戏定时器
            this->hide(); // 隐藏当前主窗口
            this->main2->show(); // 显示第二个主窗口
        }
    });

    // 连接第二个主窗口的信号next，关闭第二个主窗口并发送切换信号
    connect(this->main2, &MainWindow2::next, [=]() {
        this->main2->close(); // 关闭第二个主窗口
        emit switch2w1(); // 发送切换信号
    });
}

void MainWindow::game2()
{
    clear(); // 清理游戏场景中的所有元素
    mTank.setX(360); // 设置主坦克的X坐标
    mTank.setY(400); // 设置主坦克的Y坐标

    // 创建围墙
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, -2, 2); // 创建左边的围墙
    }
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, 33, 2); // 创建右边的围墙
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(-1, i, 2); // 创建上边的围墙
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(18, i, 2); // 创建下边的围墙
    }

    // 根据地图数组map2创建具体的建筑物
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 18; j++) {
            if (map2[j][i] != 0) {
                BuildingCreate(j, i, map2[j][i]); // 根据地图数组创建指定类型的建筑物
            }
        }
    }

    mTank.HP = hp; // 设置主坦克的生命值为初始生命值
    showHeart(mTank.HP); // 显示与主坦克生命值对应数量的心型图标

    // 定时创建敌方坦克
    for (int i = 1; i <= 5; i++) {
        QTimer::singleShot(5000 * i, this, [=]() {
            CreatEnemy(200, 150); // 在指定位置创建敌方坦克
        });
        QTimer::singleShot(10000 * i, this, [=]() {
            CreatEnemy(760, 200); // 在指定位置创建敌方坦克
        });
    }

    GTime2 = new QTimer(this); // 创建游戏定时器对象
    GTime2->start(100); // 启动定时器，每100毫秒触发一次
    connect(GTime2, &QTimer::timeout, [this]() {
        if (killnum >= 10) { // 如果击败敌人数量达到10个
            killnum = 0; // 重置击败敌人数量
            if (mTank.HP == hp) { // 如果主坦克的生命值与初始生命值相同
                Ehp++; // 敌方坦克的生命值增加
            }
            accomplishment++; // 完成数增加
            GTime2->stop(); // 停止游戏定时器
            this->hide(); // 隐藏当前主窗口
            this->main2->show(); // 显示第二个主窗口
        }
    });

    // 连接第二个主窗口的信号next，关闭第二个主窗口并发送切换信号
    connect(this->main2, &MainWindow2::next, [=]() {
        this->main2->close(); // 关闭第二个主窗口
        emit switch2w1(); // 发送切换信号
    });
}

void MainWindow::game3()
{
    QTimer::singleShot(100, this, [this]{ emit changeMusic(2); }); // 发送改变音乐信号，延时100毫秒执行
    clear(); // 清理游戏场景中的所有元素
    mTank.setX(560); // 设置主坦克的X坐标
    mTank.setY(400); // 设置主坦克的Y坐标

    // 创建围墙
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, -2, 2); // 创建左边的围墙
    }
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, 33, 2); // 创建右边的围墙
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(-1, i, 2); // 创建上边的围墙
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(18, i, 2); // 创建下边的围墙
    }

    // 根据地图数组map3创建具体的建筑物
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 18; j++) {
            if (map3[j][i] != 0) {
                BuildingCreate(j, i, map3[j][i]); // 根据地图数组创建指定类型的建筑物
            }
        }
    }

    mTank.HP = hp; // 设置主坦克的生命值为初始生命值
    showHeart(mTank.HP); // 显示与主坦克生命值对应数量的心型图标

    // 定时创建敌方坦克
    for (int i = 1; i <= 5; i++) {
        QTimer::singleShot(5000 * i, this, [=]() {
            CreatEnemy(200, 150); // 在指定位置创建敌方坦克
        });
        QTimer::singleShot(10000 * i, this, [=]() {
            CreatEnemy(760, 200); // 在指定位置创建敌方坦克
        });
    }

    GTime3 = new QTimer(this); // 创建游戏定时器对象
    GTime3->start(100); // 启动定时器，每100毫秒触发一次
    connect(GTime3, &QTimer::timeout, [this]() {
        if (killnum >= 10) { // 如果击败敌人数量达到10个
            killnum = 0; // 重置击败敌人数量
            if (mTank.HP == hp) { // 如果主坦克的生命值与初始生命值相同
                Ehp++; // 敌方坦克的生命值增加
            }
            accomplishment++; // 完成数增加
            GTime3->stop(); // 停止游戏定时器
            this->hide(); // 隐藏当前主窗口
            this->main2->show(); // 显示第二个主窗口
        }
    });

    // 连接第二个主窗口的信号next，关闭第二个主窗口并发送切换信号
    connect(this->main2, &MainWindow2::next, [=]() {
        this->main2->close(); // 关闭第二个主窗口
        emit switch2w1(); // 发送切换信号
    });
}

void MainWindow::game4()
{
    clear(); // 清理游戏场景中的所有元素
    mTank.setX(560); // 设置主坦克的X坐标
    mTank.setY(400); // 设置主坦克的Y坐标

    // 创建围墙
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, -2, 2); // 创建左边的围墙
    }
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, 33, 2); // 创建右边的围墙
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(-1, i, 2); // 创建上边的围墙
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(18, i, 2); // 创建下边的围墙
    }

    // 根据地图数组map4创建具体的建筑物
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 18; j++) {
            if (map4[j][i] != 0) {
                BuildingCreate(j, i, map4[j][i]); // 根据地图数组创建指定类型的建筑物
            }
        }
    }

    mTank.HP = hp; // 设置主坦克的生命值为初始生命值
    showHeart(mTank.HP); // 显示与主坦克生命值对应数量的心型图标

    // 定时创建敌方坦克
    for (int i = 1; i <= 5; i++) {
        QTimer::singleShot(5000 * i, this, [=]() {
            CreatEnemy(200, 150); // 在指定位置创建敌方坦克
        });
        QTimer::singleShot(10000 * i, this, [=]() {
            CreatEnemy(760, 200); // 在指定位置创建敌方坦克
        });
    }

    GTime4 = new QTimer(this); // 创建游戏定时器对象
    GTime4->start(100); // 启动定时器，每100毫秒触发一次
    connect(GTime4, &QTimer::timeout, [this]() {
        if (killnum >= 10) { // 如果击败敌人数量达到10个
            killnum = 0; // 重置击败敌人数量
            if (mTank.HP == hp) { // 如果主坦克的生命值与初始生命值相同
                Ehp++; // 敌方坦克的生命值增加
            }
            accomplishment++; // 完成数增加
            GTime4->stop(); // 停止游戏定时器
            this->hide(); // 隐藏当前主窗口
            this->main2->show(); // 显示第二个主窗口
        }
    });

    // 连接第二个主窗口的信号next，关闭第二个主窗口并发送切换信号
    connect(this->main2, &MainWindow2::next, [=]() {
        this->main2->close(); // 关闭第二个主窗口
        emit switch2w1(); // 发送切换信号
    });
}

void MainWindow::game5()
{
    QTimer::singleShot(100, this, [this]{ emit changeMusic(3); }); // 发送改变音乐信号，延时100毫秒执行
    clear(); // 清理游戏场景中的所有元素
    mTank.setX(560); // 设置主坦克的X坐标
    mTank.setY(400); // 设置主坦克的Y坐标

    // 创建围墙
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, -2, 2); // 创建左边的围墙
    }
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, 33, 2); // 创建右边的围墙
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(-1, i, 2); // 创建上边的围墙
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(18, i, 2); // 创建下边的围墙
    }

    // 根据地图数组map5创建具体的建筑物
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 18; j++) {
            if (map5[j][i] != 0) {
                BuildingCreate(j, i, map5[j][i]); // 根据地图数组创建指定类型的建筑物
            }
        }
    }

    mTank.HP = hp; // 设置主坦克的生命值为初始生命值
    showHeart(mTank.HP); // 显示与主坦克生命值对应数量的心型图标

    // 定时创建敌方坦克
    for (int i = 1; i <= 5; i++) {
        QTimer::singleShot(5000 * i, this, [=]() {
            CreatEnemy(200, 150); // 在指定位置创建敌方坦克
        });
        QTimer::singleShot(10000 * i, this, [=]() {
            CreatEnemy(760, 200); // 在指定位置创建敌方坦克
        });
    }

    GTime5 = new QTimer(this); // 创建游戏定时器对象
    GTime5->start(100); // 启动定时器，每100毫秒触发一次
    connect(GTime5, &QTimer::timeout, [this]() {
        if (killnum >= 10) { // 如果击败敌人数量达到10个
            killnum = 0; // 重置击败敌人数量
            Ehp = 2; // 游戏结束，回归初始敌方坦克生命值
            accomplishment++; // 完成数增加
            GTime5->stop(); // 停止游戏定时器
            this->hide(); // 隐藏当前主窗口
            this->main2->show(); // 显示第二个主窗口
        }
    });

    // 连接第二个主窗口的信号next，关闭第二个主窗口并发送切换信号
    connect(this->main2, &MainWindow2::next, [=]() {
        this->main2->close(); // 关闭第二个主窗口
        emit switch2w1(); // 发送切换信号
    });
}

void MainWindow::game6()
{
    clear(); // 清理游戏场景中的所有元素
    mTank.setX(560); // 设置主坦克的X坐标
    mTank.setY(400); // 设置主坦克的Y坐标
    mTank.HP = hp; // 设置主坦克的生命值为初始生命值
    showHeart(mTank.HP); // 显示与主坦克生命值对应数量的心型图标

    // 创建围墙
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, -2, 2); // 创建左边的围墙
    }
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, 33, 2); // 创建右边的围墙
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(-1, i, 2); // 创建上边的围墙
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(18, i, 2); // 创建下边的围墙
    }

    CreatBoss(400, 100); // 创建Boss坦克，指定位置

    GTime6 = new QTimer(this); // 创建游戏定时器对象
    GTime6->start(100); // 启动定时器，每100毫秒触发一次
    connect(GTime6, &QTimer::timeout, [this]() {
        if (killnum >= 1) { // 如果击败Boss坦克数量达到1个
            killnum = 0; // 重置击败敌人数量
            accomplishment++; // 完成数增加
            GTime6->stop(); // 停止游戏定时器
            this->main2->show(); // 显示第二个主窗口
            this->hide(); // 隐藏当前主窗口
        }
    });

    // 连接第二个主窗口的信号next，关闭第二个主窗口并发送切换信号
    connect(this->main2, &MainWindow2::next, [=]() {
        this->main2->close(); // 关闭第二个主窗口
        emit switch2w1(); // 发送切换信号
    });
}

void MainWindow::gameOver()
{
    if (mTank.HP <= 0) { // 如果主坦克生命值小于等于0
        mTank.HP = hp; // 重置主坦克的生命值为初始生命值
        this->hide(); // 隐藏当前主窗口
        this->main3->show(); // 显示第三个主窗口
    }
}

void MainWindow::fromw2main()
{
    emit switch2main(); // 发送切换到主窗口的信号
}

void MainWindow::switchOn()
{
    this->show(); // 显示当前主窗口

    switch (count) {
        case 0: game2(); break; // 切换到game2函数，即第二个游戏模式
        case 1: game3(); break; // 切换到game3函数，即第三个游戏模式
        case 2: game4(); break; // 切换到game4函数，即第四个游戏模式
        case 3: game5(); break; // 切换到game5函数，即第五个游戏模式
        case 4: game6(); break; // 切换到game6函数，即第六个游戏模式
    }
    count++; // 游戏模式计数器加一，准备切换到下一个游戏模式
}
