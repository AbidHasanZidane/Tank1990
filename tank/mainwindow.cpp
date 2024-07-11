#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建游戏第二窗口和游戏结束窗口的实例
    this->main2 = new MainWindow2;
    this->main3 = new GameOver;

    // 从文件中读取玩家坦克的生命值和速度
    QFile Hfile("://90Tank/player_tank/HP.txt");
    if (Hfile.open(QIODevice::ReadOnly)) {
        QTextStream HtxtInput(&Hfile);
        QString HlineStr;
        while (!HtxtInput.atEnd()) {
            HlineStr = HtxtInput.readLine();
            hp = HlineStr.toInt();
            mTank.HP = HlineStr.toInt();
        }
        Hfile.close();
    }

    QFile Sfile("://90Tank/player_tank/Speed.txt");
    if (Sfile.open(QIODevice::ReadOnly)) {
        QTextStream StxtInput(&Sfile);
        QString SlineStr;
        while (!StxtInput.atEnd()) {
            SlineStr = StxtInput.readLine();
            mTank.mTankSpeed = SlineStr.toInt();
        }
        Sfile.close();
    }

    // 设置主窗口大小和游戏视图大小
    this->setFixedSize(1320, 790);
    mGameView.setSceneRect(QRect(0, 0, 1280, 720));
    mScene.setSceneRect(QRect(0, 0, 1280, 720));

    // 设置背景图片并添加到场景中
    mBackGround.setPixmap(QPixmap("://90Tank/start/8114UVRG{SC5(IMLK}5XH3D.png"));
    mScene.addItem(&mBackGround);

    // 将玩家坦克添加到场景中
    mScene.addItem(&mTank);

    // 将游戏视图设置为主窗口的中心部件
    mGameView.setScene(&mScene);
    mGameView.setParent(this);
    setCentralWidget(&mGameView);

    // 显示游戏视图
    mGameView.show();

    // 初始化游戏中的敌人和碰撞检测
    EnemyBoom();
    EnemyMove();
    myTankCollide1();
    myTankCollide2();
    BuildingCollide1();
    BuildingCollide2();
    BuildingCollide3();
    BuildingCollide4();

    // 子弹移动定时器和发射函数连接
    BulletTime = new QTimer(this);
    BulletTime->start(50);
    connect(BulletTime, &QTimer::timeout, [this]() {
        for (auto bullet : mBullet) {
            bullet->BulletMove();
        }
    });

    // 敌方子弹发射函数
    eBulletShoot();

    // 开始第一关游戏
    game1();

    // 游戏定时器，每隔100ms检测游戏是否结束
    Time = new QTimer(this);
    Time->start(100);
    connect(Time, &QTimer::timeout, this, &MainWindow::gameOver);

    // 子弹射击定时器，每隔500ms发射一次子弹
    Time2 = new QTimer(this);
    Time2->start(500);
    connect(Time2, &QTimer::timeout, this, &MainWindow::BulletShoot2);

    // 游戏结束窗口的重试按钮连接，点击后重新启动游戏进程
    connect(this->main3, &GameOver::retry, [=]() {
        this->main3->close();
        QProcess::startDetached(qApp->applicationFilePath(), QStringList());
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    // 设置坦克变换原点为其边界框的中心点
    mTank.setTransformOriginPoint(mTank.boundingRect().center());

    // 根据按键事件处理坦克的移动和旋转
    switch(event->key()) {
    case Qt::Key_W: {
        // 向上移动，朝向角度为0度
        mTank.setRotation(0);
        mTank.moveBy(0, -mTank.mTankSpeed);
        break;
    }
    case Qt::Key_S: {
        // 向下移动，朝向角度为180度
        mTank.setRotation(180);
        mTank.moveBy(0, mTank.mTankSpeed);
        break;
    }
    case Qt::Key_A: {
        // 向左移动，朝向角度为270度
        mTank.setRotation(270);
        mTank.moveBy(-mTank.mTankSpeed, 0);
        break;
    }
    case Qt::Key_D: {
        // 向右移动，朝向角度为90度
        mTank.setRotation(90);
        mTank.moveBy(mTank.mTankSpeed, 0);
        break;
    }
    case Qt::Key_J: {
        // 按下J键，发射子弹
        BulletMove.append(Qt::Key_J);
        break;
    }
    case Qt::Key_F: {
        // 按下F键，输出当前击杀数到调试信息
        qDebug() << killnum << endl;
        break;
    }
    case Qt::Key_K: {
        // 按下K键，执行某些数据操作（注释部分）
        // DataMod();
        break;
    }
    };

    // 碰撞检测，确保坦克不会超出游戏场景的边界
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
    // 处理释放按键事件
    switch(event->key()) {
    case Qt::Key_J:
        // 释放J键，移除子弹发射标记
        BulletMove.removeAll(Qt::Key_J);
        break;
    }
}
void MainWindow::BulletShoot()
{
    // 创建子弹的图像对象
    QPixmap bulletImg("://90Tank/player_tank/girls_preview.png");

    // 根据坦克的朝向创建子弹并添加到场景和子弹列表中
    if (mTank.rotation() == 0) {
        QPoint pos(mTank.x() + mTank.pixmap().width() / 2, mTank.y());
        Bullet* bullet = new Bullet(pos, bulletImg, 'N');
        bullet->setRotation(0);
        mScene.addItem(bullet);
        mBullet.append(bullet);
    }

    if (mTank.rotation() == 180) {
        QPoint pos(mTank.x() + mTank.pixmap().width() / 2, mTank.y() + mTank.pixmap().height());
        Bullet* bullet = new Bullet(pos, bulletImg, 'S');
        bullet->setRotation(180);
        mScene.addItem(bullet);
        mBullet.append(bullet);
    }

    if (mTank.rotation() == 90) {
        QPoint pos(mTank.x() + mTank.pixmap().width(), mTank.y() + mTank.pixmap().height() / 2);
        Bullet* bullet = new Bullet(pos, bulletImg, 'E');
        bullet->setRotation(90);
        mScene.addItem(bullet);
        mBullet.append(bullet);
    }

    if (mTank.rotation() == 270) {
        QPoint pos(mTank.x(), mTank.y() + mTank.pixmap().height() / 2);
        Bullet* bullet = new Bullet(pos, bulletImg, 'W');
        bullet->setRotation(270);
        mScene.addItem(bullet);
        mBullet.append(bullet);
    }
}

void MainWindow::BulletShoot2()
{
    // 根据按键列表发射子弹
    for (int keyCode : BulletMove) {
        if (keyCode == Qt::Key_J) {
            BulletShoot();
        }
    }
}

void MainWindow::EnemyShoot()
{
    // 创建敌人子弹的图像对象
    QPixmap ebulletImg("://90Tank/enemy/pic_13step.png");

    // 遍历所有敌人，根据其朝向创建子弹并添加到场景和敌人子弹列表中
    for (auto enemy : mEnemy) {
        if (enemy->rotation() == 0) {
            QPoint pos(enemy->x() + enemy->pixmap().width() / 2, enemy->y());
            enemyBullet* ebullet = new enemyBullet(pos, ebulletImg, 'N');
            ebullet->setRotation(0);
            mScene.addItem(ebullet);
            eBullet.append(ebullet);
        }

        if (enemy->rotation() == 180) {
            QPoint pos(enemy->x() + enemy->pixmap().width() / 2, enemy->y() + enemy->pixmap().height());
            enemyBullet* ebullet = new enemyBullet(pos, ebulletImg, 'S');
            ebullet->setRotation(180);
            mScene.addItem(ebullet);
            eBullet.append(ebullet);
        }

        if (enemy->rotation() == 90) {
            QPoint pos(enemy->x() + enemy->pixmap().width(), enemy->y() + enemy->pixmap().height() / 2);
            enemyBullet* ebullet = new enemyBullet(pos, ebulletImg, 'E');
            ebullet->setRotation(90);
            mScene.addItem(ebullet);
            eBullet.append(ebullet);
        }

        if (enemy->rotation() == 270) {
            QPoint pos(enemy->x(), enemy->y() + enemy->pixmap().height() / 2);
            enemyBullet* ebullet = new enemyBullet(pos, ebulletImg, 'W');
            ebullet->setRotation(270);
            mScene.addItem(ebullet);
            eBullet.append(ebullet);
        }
    }
}
void MainWindow::eBulletShoot()
{
    // 创建定时器并启动，每隔2秒触发一次EnemyShoot函数
    Time = new QTimer(this);
    Time->start(2000);
    connect(Time, &QTimer::timeout, [this]() {
        EnemyShoot();
    });

    // 初始时立即调用EnemyShoot函数
    EnemyShoot();

    // 创建定时器并启动，每隔50毫秒触发一次移动敌方子弹的函数
    Time2 = new QTimer(this);
    Time2->start(50);
    connect(Time2, &QTimer::timeout, [this]() {
        for (auto bullet : eBullet) {
            bullet->eBulletMove();
        }
    });
}

void MainWindow::CreatEnemy(int x, int y)
{
    // 创建敌人对象并添加到场景中及敌人列表中
    Enemy* enemy = new Enemy(x, y);
    mScene.addItem(enemy);
    mEnemy.append(enemy);
}

void MainWindow::EnemyBoom()
{
    // 创建定时器并启动，每隔10毫秒检测子弹与敌人的碰撞及处理爆炸效果
    Time = new QTimer(this);
    Time->start(10);
    connect(Time, &QTimer::timeout, [this]() {
        for (auto enemy : mEnemy) {
            for (auto bullet : mBullet) {
                if (bullet->collidesWithItem(enemy)) {
                    // 移除子弹并销毁
                    mBullet.removeOne(bullet);
                    bullet->deleteLater();
                    // 移除敌人并设置爆炸动画
                    mEnemy.removeOne(enemy);
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
                        enemy->deleteLater();
                    });
                    // 更新得分和击败敌人数量
                    killnum++;
                    grade += 100;
                }
            }
        }
    });
}

void MainWindow::EnemyMove()
{
    // 创建定时器并启动，每隔1秒随机改变敌人移动的方向
    Time2 = new QTimer(this);
    Time2->start(1000);
    connect(Time2, &QTimer::timeout, [this]() {
        dir = rand();
    });

    // 创建定时器并启动，每隔100毫秒更新敌人的移动状态
    Time = new QTimer(this);
    Time->start(100);
    connect(Time, &QTimer::timeout, [this]() {
        for (auto enemy : mEnemy) {
            // 设置敌人的旋转和移动方向
            enemy->setTransformOriginPoint(enemy->boundingRect().center());
            if (dir % 2 == 1) {
                if (mTank.x() > enemy->x()) {
                    enemy->setRotation(90);
                    enemy->moveBy(enemy->enemySpeed, 0);
                }
                if (mTank.x() < enemy->x()) {
                    enemy->setRotation(270);
                    enemy->moveBy(-enemy->enemySpeed, 0);
                }
            }
            if (dir % 2 == 0) {
                if (mTank.y() < enemy->y()) {
                    enemy->setRotation(0);
                    enemy->moveBy(0, -enemy->enemySpeed);
                }
                if (mTank.y() > enemy->y()) {
                    enemy->setRotation(180);
                    enemy->moveBy(0, enemy->enemySpeed);
                }
            }
        }
    });
}

void MainWindow::myTankCollide1()
{
    // 创建定时器并启动，每隔10毫秒检测我方坦克与敌人的碰撞及处理逻辑
    Time = new QTimer(this);
    Time->start(10);
    connect(Time, &QTimer::timeout, [this]() {
        for (auto enemy : mEnemy) {
            if (mTank.collidesWithItem(enemy)) {
                // 如果我方坦克与敌人碰撞，则移除敌人并触发爆炸效果动画
                mEnemy.removeOne(enemy);
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
                    enemy->deleteLater();
                });

                // 停止我方坦克的移动，并设置爆炸动画及复位处理
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
                QTimer::singleShot(250, this, [=]() {
                    // 复位我方坦克位置和速度，并减少生命值
                    mTank.setPixmap(QPixmap("://90Tank/player_tank/mTank.png"));
                    mTank.setX(200);
                    mTank.setY(200);
                    mTank.mTankSpeed = 10;
                    mTank.HP--;
                });

                // 增加击败敌人数量和得分
                killnum++;
                grade += 100;
            }
        }
    });
}

void MainWindow::myTankCollide2()
{
    // 创建定时器并启动，每隔10毫秒检测我方坦克与敌方子弹的碰撞及处理逻辑
    Time = new QTimer(this);
    Time->start(10);
    connect(Time, &QTimer::timeout, [this]() {
        for (auto bullet : eBullet) {
            if (bullet->collidesWithItem(&mTank)) {
                // 如果我方坦克被敌方子弹击中，则移除子弹并触发爆炸动画及停止我方坦克移动
                eBullet.removeOne(bullet);
                bullet->deleteLater();
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
                QTimer::singleShot(250, this, [=]() {
                    // 复位我方坦克位置和速度，并减少生命值
                    mTank.setPixmap(QPixmap("://90Tank/player_tank/mTank.png"));
                    mTank.setX(200);
                    mTank.setY(200);
                    mTank.mTankSpeed = 10;
                    mTank.HP--;
                });
            }
        }
    });
}

void MainWindow::BuildingCreate(int y, int x, int kind)
{
    // 创建建筑物对象，并添加到场景和建筑物列表中
    Building* building = new Building(y, x, kind);
    mScene.addItem(building);
    mBuilding.append(building);
}

void MainWindow::BuildingCollide1()
{
    // 创建定时器并启动，每隔10毫秒检测建筑物与子弹的碰撞及处理逻辑
    Time = new QTimer(this);
    Time->start(10);
    connect(Time, &QTimer::timeout, [this]() {
        for (auto building : mBuilding) {
            for (auto bullet : mBullet) {
                if (building->collidesWithItem(bullet)) {
                    // 根据建筑物种类不同执行不同的碰撞处理
                    if (building->kind == 1) {
                        mBullet.removeOne(bullet);
                        bullet->deleteLater();
                        mBuilding.removeOne(building);
                        building->deleteLater();
                    }
                    else if (building->kind == 2) {
                        mBullet.removeOne(bullet);
                        bullet->deleteLater();
                    }
                    else if (building->kind == 3) {
                        // 重新添加建筑物以刷新其显示
                        mScene.removeItem(building);
                        mScene.addItem(building);
                    }
                }
            }
        }
    });
}

void MainWindow::BuildingCollide2()
{
    // 创建定时器并启动，每隔1毫秒检测我方坦克与建筑物的碰撞及处理逻辑
    Time = new QTimer(this);
    Time->start(1);
    connect(Time, &QTimer::timeout, [this]() {
        for (auto building : mBuilding) {
            if (mTank.collidesWithItem(building)) {
                // 根据建筑物种类不同，调整我方坦克的位置以避免穿越建筑物
                if (building->kind != 3) {
                    if (mTank.rotation() == 0) {
                        mTank.setY(building->y() + building->pixmap().height());
                        mTank.setX(mTank.x());
                    }
                    else if (mTank.rotation() == 180) {
                        mTank.setY(building->y() - mTank.pixmap().height());
                        mTank.setX(mTank.x());
                    }
                    else if (mTank.rotation() == 90) {
                        mTank.setY(mTank.y());
                        mTank.setX(building->x() - mTank.pixmap().width());
                    }
                    else if (mTank.rotation() == 270) {
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
    // 创建定时器并启动，每隔1毫秒检测敌人与建筑物的碰撞及处理逻辑
    Time = new QTimer(this);
    Time->start(1);
    connect(Time, &QTimer::timeout, [this]() {
        for (auto building : mBuilding) {
            for (auto enemy : mEnemy) {
                if (enemy->collidesWithItem(building)) {
                    // 根据建筑物种类不同，调整敌人的位置以避免穿越建筑物
                    if (building->kind != 3) {
                        if (enemy->rotation() == 0) {
                            enemy->setY(building->y() + building->pixmap().height());
                            enemy->setX(enemy->x());
                        }
                        else if (enemy->rotation() == 180) {
                            enemy->setY(building->y() - enemy->pixmap().height());
                            enemy->setX(enemy->x());
                        }
                        else if (enemy->rotation() == 90) {
                            enemy->setY(enemy->y());
                            enemy->setX(building->x() - enemy->pixmap().width());
                        }
                        else if (enemy->rotation() == 270) {
                            enemy->setY(enemy->y());
                            enemy->setX(building->x() + building->pixmap().width());
                        }
                    }
                    
                    // 如果建筑物是类型3，则重新添加以刷新显示
                    if (building->kind == 3) {
                        mScene.removeItem(building);
                        mScene.addItem(building);
                    }
                    
                    // 边界检测，防止敌人超出游戏场景边界
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
    // 创建定时器并启动，每隔10毫秒检测建筑物与敌方子弹的碰撞及处理逻辑
    Time = new QTimer(this);
    Time->start(10);
    connect(Time, &QTimer::timeout, [this]() {
        for (auto building : mBuilding) {
            for (auto bullet : eBullet) {
                if (building->collidesWithItem(bullet)) {
                    // 根据建筑物种类不同执行不同的碰撞处理
                    if (building->kind == 1) {
                        eBullet.removeOne(bullet);
                        bullet->deleteLater();
                        mBuilding.removeOne(building);
                        building->deleteLater();
                    }
                    else if (building->kind == 2) {
                        eBullet.removeOne(bullet);
                        bullet->deleteLater();
                    }
                    else if (building->kind == 3) {
                        // 重新添加建筑物以刷新其显示
                        mScene.removeItem(building);
                        mScene.addItem(building);
                    }
                }
            }
        }
    });
}

void MainWindow::clear()
{
    // 清理建筑物、敌人和子弹列表，并释放相应的内存资源
    for (auto building : mBuilding) {
        mBuilding.removeOne(building);
        building->deleteLater();
    }
    for (auto enemy : mEnemy) {
        mEnemy.removeOne(enemy);
        enemy->deleteLater();
    }
    for (auto bullet : mBullet) {
        mBullet.removeOne(bullet);
        bullet->deleteLater();
    }
}

void MainWindow::game1()
{
    // 清理游戏场景中的所有元素
    clear();

    // 设置玩家坦克的初始位置
    mTank.setX(560);
    mTank.setY(400);

    // 创建边界建筑物
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, -2, 2);
    }
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, 33, 2);
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(-1, i, 2);
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(18, i, 2);
    }

    // 根据地图数据创建建筑物
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 18; j++) {
            if (map1[j][i] != 0) {
                BuildingCreate(j, i, map1[j][i]);
            }
        }
    }

    // 设置玩家坦克的生命值和击杀数
    mTank.HP = hp;
    killnum = 0;

    // 分批次创建敌人，并设置定时器控制敌人的生成
    for (int i = 1; i <= 5; i++) {
        QTimer::singleShot(5000 * i, this, [=]() {
            CreatEnemy(200, 600);
        });
        QTimer::singleShot(10000 * i, this, [=]() {
            CreatEnemy(1100, 600);
        });
    }

    // 创建并启动游戏计时器，监测是否满足过关条件
    GTime1 = new QTimer(this);
    GTime1->start(100);
    connect(GTime1, &QTimer::timeout, [this]() {
        if (killnum >= 10) {
            killnum = 0;
            GTime1->stop();
            // 隐藏当前主窗口，显示游戏2的主窗口
            this->hide();
            this->main2->show();
        }
    });

    // 连接游戏2的信号，当游戏2完成时继续执行
    connect(this->main2, &MainWindow2::next, [=]() {
        this->show();
        this->main2->close();
        game2();
    });
}

void MainWindow::game2()
{
    // 清理游戏场景中的所有元素
    clear();

    // 设置玩家坦克的初始位置
    mTank.setX(360);
    mTank.setY(400);

    // 创建边界建筑物
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, -2, 2);
    }
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, 33, 2);
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(-1, i, 2);
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(18, i, 2);
    }

    // 根据地图数据创建建筑物
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 18; j++) {
            if (map2[j][i] != 0) {
                BuildingCreate(j, i, map2[j][i]);
            }
        }
    }

    // 设置玩家坦克的生命值
    mTank.HP = hp;

    // 分批次创建敌人，并设置定时器控制敌人的生成
    for (int i = 1; i <= 5; i++) {
        QTimer::singleShot(5000 * i, this, [=]() {
            CreatEnemy(200, 150);
        });
        QTimer::singleShot(10000 * i, this, [=]() {
            CreatEnemy(760, 200);
        });
    }

    // 创建并启动游戏计时器，监测是否满足过关条件
    GTime2 = new QTimer(this);
    GTime2->start(100);
    connect(GTime2, &QTimer::timeout, [this]() {
        if (killnum >= 10) {
            killnum = 0;
            GTime2->stop();
            // 隐藏当前主窗口，显示游戏2的主窗口
            this->hide();
            this->main2->show();
        }
    });

    // 连接游戏2的信号，当游戏2完成时继续执行
    connect(this->main2, &MainWindow2::next, [=]() {
        this->show();
        this->main2->close();
        game3();
    });

    // 连接游戏失败后的重试信号
    connect(this->main3, &GameOver::retry, [=]() {
        this->close();
        this->show();
    });
}


void MainWindow::game3()
{
    // 清理游戏场景中的所有元素
    clear();

    // 设置玩家坦克的初始位置
    mTank.setX(560);
    mTank.setY(400);

    // 创建边界建筑物
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, -2, 2);
    }
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, 33, 2);
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(-1, i, 2);
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(18, i, 2);
    }

    // 根据地图数据创建建筑物
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 18; j++) {
            if (map3[j][i] != 0) {
                BuildingCreate(j, i, map3[j][i]);
            }
        }
    }

    // 设置玩家坦克的生命值
    mTank.HP = hp;

    // 分批次创建敌人，并设置定时器控制敌人的生成
    for (int i = 1; i <= 5; i++) {
        QTimer::singleShot(5000 * i, this, [=]() {
            CreatEnemy(200, 150);
        });
        QTimer::singleShot(10000 * i, this, [=]() {
            CreatEnemy(760, 200);
        });
    }

    // 创建并启动游戏计时器，监测是否满足过关条件
    GTime3 = new QTimer(this);
    GTime3->start(100);
    connect(GTime3, &QTimer::timeout, [this]() {
        if (killnum >= 10) {
            killnum = 0;
            GTime3->stop();
        }
    });

    // 连接游戏2的信号，当游戏2完成时继续执行下一关
    connect(this->main2, &MainWindow2::next, [=]() {
        this->show();
        this->main2->close();
        game4();
    });
}

void MainWindow::game4()
{
    // 清理游戏场景中的所有元素
    clear();

    // 设置玩家坦克的初始位置
    mTank.setX(560);
    mTank.setY(400);

    // 创建边界建筑物
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, -2, 2);
    }
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, 33, 2);
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(-1, i, 2);
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(18, i, 2);
    }

    // 根据地图数据创建建筑物
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 18; j++) {
            if (map4[j][i] != 0) {
                BuildingCreate(j, i, map4[j][i]);
            }
        }
    }

    // 设置玩家坦克的生命值
    mTank.HP = hp;

    // 分批次创建敌人，并设置定时器控制敌人的生成
    for (int i = 1; i <= 5; i++) {
        QTimer::singleShot(5000 * i, this, [=]() {
            CreatEnemy(200, 150);
        });
        QTimer::singleShot(10000 * i, this, [=]() {
            CreatEnemy(760, 200);
        });
    }

    // 创建并启动游戏计时器，监测是否满足过关条件
    GTime4 = new QTimer(this);
    GTime4->start(100);
    connect(GTime4, &QTimer::timeout, [this]() {
        if (killnum >= 10) {
            killnum = 0;
            GTime4->stop();
        }
    });

    // 连接游戏2的信号，当游戏2完成时继续执行下一关
    connect(this->main2, &MainWindow2::next, [=]() {
        this->show();
        this->main2->close();
        game5();
    });
}

void MainWindow::game5()
{
    // 清理游戏场景中的所有元素
    clear();

    // 设置玩家坦克的初始位置
    mTank.setX(560);
    mTank.setY(400);

    // 创建边界建筑物
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, -2, 2);
    }
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, 33, 2);
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(-1, i, 2);
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(18, i, 2);
    }

    // 根据地图数据创建建筑物
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 18; j++) {
            if (map5[j][i] != 0) {
                BuildingCreate(j, i, map5[j][i]);
            }
        }
    }

    // 设置玩家坦克的生命值
    mTank.HP = hp;

    // 分批次创建敌人，并设置定时器控制敌人的生成
    for (int i = 1; i <= 5; i++) {
        QTimer::singleShot(5000 * i, this, [=]() {
            CreatEnemy(200, 150);
        });
        QTimer::singleShot(10000 * i, this, [=]() {
            CreatEnemy(760, 200);
        });
    }
}

void MainWindow::gameOver()
{
    // 判断玩家坦克生命值是否小于等于0，若是则执行游戏结束逻辑
    if (mTank.HP <= 0) {
        // 重置玩家坦克生命值
        mTank.HP = hp;
        
        // 隐藏当前游戏窗口，显示游戏结束界面
        this->hide();
        this->main3->show();
    }
}

}
