#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(1290, 754);  // 设置窗口大小

    mGameView.setSceneRect(QRect(0, 0, 1280, 720));  // 设置游戏视图场景大小

    mScene.setSceneRect(QRect(0, 0, 1280, 720));  // 设置游戏场景大小

    mBackGround.setPixmap(QPixmap("://90Tank/start/8114UVRG{SC5(IMLK}5XH3D.png"));  // 设置背景图片

    mScene.addItem(&mBackGround);  // 将背景图片添加到场景中

    mScene.addItem(&mTank);  // 将我方坦克添加到场景中

    mGameView.setScene(&mScene);  // 将场景设置到游戏视图中

    mGameView.setParent(this);

    mGameView.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);  // 设置水平滚动条不可见
    mGameView.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);    // 设置垂直滚动条不可见
    mGameView.setResizeAnchor(QGraphicsView::NoAnchor);               // 设置视图大小不随窗口改变

    setCentralWidget(&mGameView);  // 将游戏视图设置为中心窗口部件

    mGameView.show();  // 显示游戏视图

    EnemyBoom();  // 开始处理敌人爆炸效果

    EnemyMove();  // 开始处理敌人移动

    myTankCollide();  // 开始处理我方坦克与敌人的碰撞

    BuildingCollide();  // 开始处理建筑物与子弹的碰撞

    BuildingCollide2();  // 开始处理建筑物与我方坦克的碰撞

    BuildingCollide3();  // 开始处理建筑物与敌人的碰撞

    BulletTime = new QTimer(this);  // 创建子弹定时器
    BulletTime->start(50);  // 启动子弹定时器，每50毫秒触发一次
    connect(BulletTime, &QTimer::timeout, [this]() {
        for (auto bullet : mBullet) {
            bullet->BulletMove();  // 子弹移动
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    mTank.setTransformOriginPoint(mTank.boundingRect().center());  // 设置坦克旋转中心为其矩形边界中心
    switch (event->key()) {
    case Qt::Key_W:
        mTank.setRotation(0);  // 设置坦克朝向上
        mTank.moveBy(0, -mTank.mTankSpeed);  // 向上移动坦克
        break;
    case Qt::Key_S:
        mTank.setRotation(180);  // 设置坦克朝向下
        mTank.moveBy(0, mTank.mTankSpeed);  // 向下移动坦克
        break;
    case Qt::Key_A:
        mTank.setRotation(270);  // 设置坦克朝向左
        mTank.moveBy(-mTank.mTankSpeed, 0);  // 向左移动坦克
        break;
    case Qt::Key_D:
        mTank.setRotation(90);  // 设置坦克朝向右
        mTank.moveBy(mTank.mTankSpeed, 0);  // 向右移动坦克
        break;
    case Qt::Key_J:
        BulletShoot();  // 发射子弹
        break;
    case Qt::Key_K:
        CreatEnemy();  // 创建敌人
        break;
    case Qt::Key_L:
        MapCreate();  // 创建地图
        break;
    };

    // 边界限制，防止坦克移出游戏窗口
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

void MainWindow::BulletShoot()
{
    QPixmap bulletImg("://90Tank/player_tank/girls_preview.png");  // 子弹图片
    if (mTank.rotation() == 0) {
        QPoint pos(mTank.x() + mTank.pixmap().width() / 2, mTank.y());  // 子弹初始位置
        Bullet* bullet = new Bullet(pos, bulletImg, 'N');  // 创建向上的子弹
        bullet->setRotation(0);  // 设置子弹旋转角度
        mScene.addItem(bullet);  // 将子弹添加到场景中
        mBullet.append(bullet);  // 将子弹添加到列表中
    }

    // 同理，创建其他方向的子弹，代码类似
     if(mTank.rotation()==180){
       QPoint pos(mTank.x()+mTank.pixmap().width()/2,mTank.y()+mTank.pixmap().height());
       Bullet* bullet=new Bullet(pos,bulletImg,'S');
       bullet->setRotation(180);
       mScene.addItem(bullet);
       mBullet.append(bullet);
   }

   if(mTank.rotation()==90){
       QPoint pos(mTank.x()+mTank.pixmap().width(),mTank.y()+mTank.pixmap().height()/2);
       Bullet* bullet=new Bullet(pos,bulletImg,'E');
       bullet->setRotation(90);
       mScene.addItem(bullet);
       mBullet.append(bullet);
   }

   if(mTank.rotation()==270){
       QPoint pos(mTank.x(),mTank.y()+mTank.pixmap().height()/2);
       Bullet* bullet=new Bullet(pos,bulletImg,'W');
       bullet->setRotation(270);
       mScene.addItem(bullet);
       mBullet.append(bullet);
   }
}

void MainWindow::CreatEnemy()
{
    Enemy* enemy = new Enemy();  // 创建敌人
    mScene.addItem(enemy);  // 将敌人添加到场景中
    mEnemy.append(enemy);  // 将敌人添加到列表中
}

void MainWindow::EnemyBoom()
{
    Time = new QTimer(this);  // 创建定时器
    Time->start(10);  // 启动定时器，每10毫秒触发一次
    connect(Time, &QTimer::timeout, [this]() {
        for (auto enemy : mEnemy)
            for (auto bullet : mBullet) {
                if (bullet->collidesWithItem(enemy)) {  // 子弹击中敌人
               mBullet.removeOne(bullet);
               bullet->deleteLater();
               mEnemy.removeOne(enemy);
               enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite.png"));
               QTimer::singleShot(50,this,[=](){
               enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite2.png"));
               });
               QTimer::singleShot(100,this,[=](){
               enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite3.png"));
               });
               QTimer::singleShot(150,this,[=](){
               enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite4.png"));
               });
               QTimer::singleShot(200,this,[=](){
               enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite5.png"));
               });
               QTimer::singleShot(200,this,[=](){
               enemy->deleteLater();
               }); // 爆炸效果处理
                }
            }
    });
}

void MainWindow::EnemyMove()
{
    Time = new QTimer(this); // 创建定时器对象
    Time->start(50); // 启动定时器，每50毫秒触发一次
    connect(Time, &QTimer::timeout, [this]() {
        for (auto enemy : mEnemy) {
            enemy->setTransformOriginPoint(enemy->boundingRect().center()); // 设置敌人旋转中心为其边界中心点
            int dir = rand() % 4; // 随机确定敌人的移动方向
            if (dir == 0) {
                enemy->setRotation(0); // 设置敌人朝向上
                enemy->moveBy(0, -10); // 向上移动敌人
            }
            if (dir == 1) {
                enemy->setRotation(180); // 设置敌人朝向下
                enemy->moveBy(0, 10); // 向下移动敌人
            }
            if (dir == 2) {
                enemy->setRotation(90); // 设置敌人朝向右
                enemy->moveBy(10, 0); // 向右移动敌人
            }
            if (dir == 3) {
                enemy->setRotation(270); // 设置敌人朝向左
                enemy->moveBy(-10, 0); // 向左移动敌人
            }
            // 边界限制，防止敌人移出游戏窗口
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
    });
}

void MainWindow::myTankCollide()
{
    Time = new QTimer(this); // 创建定时器对象
    Time->start(10); // 启动定时器，每10毫秒触发一次
    connect(Time, &QTimer::timeout, [this]() {
        for (auto enemy : mEnemy) {
            if (mTank.collidesWithItem(enemy)) { // 检测我方坦克是否与敌人碰撞
                mTank.mTankSpeed = 0; // 停止我方坦克移动
                // 播放坦克爆炸效果动画
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
                    mTank.setPixmap(QPixmap("://90Tank/player_tank/mTank.png"));
                    mTank.setX(200); // 重置坦克位置
                    mTank.setY(200);
                    mTank.mTankSpeed = 10; // 恢复坦克移动速度
                });
            }
        }
    });
}

void MainWindow::BuildingCreate(int y, int x, int kind)
{
    Building* building = new Building(y, x, kind); // 创建建筑物对象
    mScene.addItem(building); // 将建筑物添加到场景中
    mBuilding.append(building); // 将建筑物对象添加到列表中
}

void MainWindow::BuildingCollide()
{
    Time = new QTimer(this); // 创建定时器对象
    Time->start(10); // 启动定时器，每10毫秒触发一次
    connect(Time, &QTimer::timeout, [this]() {
        for (auto building : mBuilding) {
            for (auto bullet : mBullet) {
                if (building->collidesWithItem(bullet)) { // 检测建筑物是否与子弹碰撞
                    if (building->kind == 1) {
                        // 如果是第一类建筑物，移除子弹和建筑物
                        mBullet.removeOne(bullet);
                        bullet->deleteLater();
                        mBuilding.removeOne(building);
                        building->deleteLater();
                    }
                    if (building->kind == 2) {
                        // 如果是第二类建筑物，移除子弹
                        mBullet.removeOne(bullet);
                        bullet->deleteLater();
                    }
                    if (building->kind == 3) {
                        // 如果是第三类建筑物，重绘建筑物
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
    Time = new QTimer(this); // 创建定时器对象
    Time->start(1); // 启动定时器，每1毫秒触发一次
    connect(Time, &QTimer::timeout, [this]() {
        for (auto building : mBuilding) {
            if (mTank.collidesWithItem(building)) { // 检测我方坦克是否与建筑物碰撞
                if (building->kind != 3) {
                    if (mTank.rotation() == 0) {
                        // 如果坦克朝上，调整坦克位置
                        mTank.setY(building->y() + building->pixmap().height());
                        mTank.setX(mTank.x());
                    }
                    if (mTank.rotation() == 180) {
                        // 如果坦克朝下，调整坦克位置
                        mTank.setY(building->y() - mTank.pixmap().height());
                        mTank.setX(mTank.x());
                    }
                    if (mTank.rotation() == 90) {
                        // 如果坦克朝右，调整坦克位置
                        mTank.setY(mTank.y());
                        mTank.setX(building->x() - mTank.pixmap().width());
                    }
                    if (mTank.rotation() == 270) {
                        // 如果坦克朝左，调整坦克位置
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
        for (auto building : mBuilding) {
            for (auto enemy : mEnemy) {
                if (enemy->collidesWithItem(building)) { // 检测敌人是否与建筑物碰撞
                    if (building->kind != 3) {
                        if (enemy->rotation() == 0) {
                            // 如果敌人朝上，调整敌人位置
                            enemy->setY(building->y() + building->pixmap().height());
                            enemy->setX(enemy->x());
                        }
                        if (enemy->rotation() == 180) {
                            // 如果敌人朝下，调整敌人位置
                            enemy->setY(building->y() - enemy->pixmap().height());
                            enemy->setX(enemy->x());
                        }
                        if (enemy->rotation() == 90) {
                            // 如果敌人朝右，调整敌人位置
                            enemy->setY(enemy->y());
                            enemy->setX(building->x() - enemy->pixmap().width());
                        }
                        if (enemy->rotation() == 270) {
                            // 如果敌人朝左，调整敌人位置
                            enemy->setY(enemy->y());
                            enemy->setX(building->x() + building->pixmap().width());
                        }
                    }
                    if (building->kind == 3) {
                        // 如果是第三类建筑物，重绘建筑物
                        mScene.removeItem(building);
                        mScene.addItem(building);
                    }
                }
            }
        }
    });
}

void MainWindow::MapCreate()//根据地图数组创建地图
{
    for(int i=0;i<32;i++){
        for(int j=0;j<18;j++){
            if(map1[j][i]!=0){
                BuildingCreate(j,i,map1[j][i]);
            }
        }
    }
}

