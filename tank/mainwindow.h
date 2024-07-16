#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QList>
#include <QTimer>
#include <QtDebug>
#include <QKeyEvent>
#include "mytank.h"
#include "bullet.h"
#include "enemy.h"
#include "building.h"
#include"enemybullet.h"
#include<QFile>
#include<QTextStream>
#include<QFileDialog>
#include"mainwindow2.h"
#include"mainwindow3.h"
#include<QPushButton>
#include"gameover.h"
#include <QApplication>
#include <QProcess>
#include"boss.h"
#include"bossbullet.h"
#include"settings.h"
#include"Heart.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
  MainWindow2* main2=NULL;
    GameOver* main3=NULL;
    MainWindow3* main4=NULL;
     //按键控制坦克移动和发射子弹
    void keyPressEvent(QKeyEvent* event);

    void keyReleaseEvent(QKeyEvent* event);
    //子弹的移动
    void BulletShoot();
    //子弹射击
    void BulletShoot2();
    //敌人射击
    void EnemyShoot();
    //Boss射击
    void BossShoot();
    //敌人子弹的移动
    void eBulletShoot();

    void bBulletShoot();
    //在（x,y）处生成敌人
    void CreatEnemy(int x,int y);

    void CreatBoss(int x,int y);
    //敌人死亡
    void EnemyBoom();

    void BossBoom();
    //敌人移动
    void EnemyMove();

    void BossMove();
    //我方与敌方坦克的碰撞判定
    void myTankCollide1();
    //我方坦克与敌方子弹的碰撞判定及我方的死亡动画
    void myTankCollide2();

    void myTankCollide3();
    //在（x,y）处创造某种建筑物
    void BuildingCreate(int x,int y,int kind);

    void BossCollide();

    //我方子弹与各类建筑物的碰撞判定
    void BuildingCollide1();
    //我方坦克与各类建筑的碰撞判定
    void BuildingCollide2();
    //敌方坦克与各类建筑的碰撞判定
    void BuildingCollide3();
    //敌方子弹与各类建筑的碰撞判定
    void BuildingCollide4();
    //显示生命值
    void showHeart(int number);
    //清除场上所有物品
    void clear();
    //第一关
    void game1();
    //第二关
    void game2();
    //第三关
    void game3();
    //第四关
    void game4();
    //第五关
    void game5();
    //第六关
    void game6();
    //游戏结束
void gameOver();
signals:
    void changeMusic(int cnt);  // 切换音乐信号，参数为计数器
    void boomEffect();  // 爆炸效果信号
    void switch2main();  // 切换到主界面信号
    void switch2w1();  // 切换到第一关界面信号

private slots:
    void fromw2main();  // 从第二关返回主界面槽函数
    void switchOn();  // 开关触发槽函数

private:
    Ui::MainWindow *ui;  // 主窗口UI指针

    QGraphicsView mGameView;  // 游戏视图对象

    QGraphicsScene mScene;  // 游戏场景对象

    QGraphicsPixmapItem mBackGround;  // 背景图片对象

    MyTank mTank;  // 玩家坦克对象

    QTimer* BulletTime;  // 子弹计时器指针

    QTimer* Time;  // 时间计时器指针

    QTimer* Time2;  // 时间2计时器指针

    QTimer* GTime1;  // 游戏时间1计时器指针

    QTimer* GTime2;  // 游戏时间2计时器指针

    QTimer* GTime3;  // 游戏时间3计时器指针

    QTimer* GTime4;  // 游戏时间4计时器指针

    QTimer* GTime5;  // 游戏时间5计时器指针

    QTimer* GTime6;  // 游戏时间6计时器指针

    QList<Bullet*> mBullet;  // 子弹列表

    QList<Enemy*> mEnemy;  // 敌人列表

    QList<Heart*> mHeart;  // 心形道具列表

    QList<Building*> mBuilding;  // 建筑物列表

    QList<enemyBullet*> eBullet;  // 敌人子弹列表

    QList<int> BulletMove;  // 子弹移动列表

    QList<BOSS*> mBoss;  // BOSS列表

    QList<BossBullet*> bBullet;  // BOSS子弹列表

    int Ehp = 2;  // 敌人生命值

    int dir;  // 方向

    int killnum;  // 击杀数量

    int grade;  // 等级

    int hp;  // 生命值

    int mtankspeed;  // 坦克速度

    int Fire;  // 火力

    int Death;  // 死亡

    int count = 0;  // 计数器

    int KillNum;  // 击杀数

    int accomplishment;  // 成就   

    //地图二维数组，数字代表建筑种类
    int map1[18][32]={
        {3, 0, 3, 0,	0,	1,	0,	0,	0,	1,	0,	0,	0,	1,	1,	0,	1,	1,	1,1,0,0,1,1,0,0,0,0,0,1,1,1},
        {0, 0, 0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	1,	1,	0,	1,	1,	1,	1,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	1},
        {3, 0, 0,	1,	1,	1,	1,	1,	1,	0,	1,	0,	0,	1,	1,	0,	0,	1,	1,	1,	0,	1,	0,	1,	1,	1,	1,	1,	1,	0,	0,	1},
        {0, 0, 0,	2,	2,	2,	2,	2,	2,	0,	0,	0,	0,	1,	1,	0,	0,	0,	1,	1,	0,	0,	0,	2,	2,	2,	2,	2,	2,	0,	0,	1},
        {0, 0, 0,	0,	0,	0,	0,	4,	0,	0,	0,	0,	0,	1,	1,	0,	0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	4,	0,	0,	0,	1},
        {0, 0, 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
        {0, 0, 0,	0,	0,	0,	0,	4,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	4,	0,	0,	0,	0},
        {0, 0, 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
        {0, 0, 0,	0,	0,	0,	0,	4,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	4,	0,	0,	0,	0},
        {0, 0, 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
        {3, 0, 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
        {},
        {},
        {},
        {0,0,0,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
        {0,0,0,	0,	0,	0,	0,	0,	0,	0,	0,	2,	2,	2,	2,	2,	2,	2,	2,	2,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
        {0,0,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
        {0,0,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0}
    };
    int map2[18][32]={
       { 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
       { 0,	0,	0,	0,	0,	0,	0,	2,	2,	2,	2,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
       { 0,	0,	0,	0,	0,	2,	2,	0,	0,	0,	0,	2,	2,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
       { 0,	0,	0,	0,	2,	3,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	0,	0,	0,	0,	2,	2,	2,	2,	0,	0,	0,	0,	0,	0,	0},
       { 0,	0,	0,	2,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	0,	2,	2,	0,	0,	0,	0,	2,	2,	0,	0,	0,	0,	0},
       { 0,	0,	0,	2,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	2,	3,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	0},
       { 0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	2,	0,	2,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0},
       { 0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	2,	0,	2,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0},
       { 0,	0,	1,	1,	0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	1,	3,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0},
       { 0,	0,	1,	1,	1,	1,	4,	0,	1,	0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0},
       { 0,	0,	0,	2,	0,	1,	0,	0,	1,	1,	1,	1,	1,	0,	2,	0,	2,	1,	0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	1,	1,	0,	0},
       { 0,	0,	0,	2,	0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	2,	0,	2,	1,	1,	1,	4,	0,	1,	0,	0,	0,	0,	1,	1,	1,	0,	0},
       { 0,	0,	0,	0,	2,	0,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	2,	0,	1,	0,	0,	1,	1,	1,	1,	1,	0,	2,	0,	0,	0},
       { 0,	0,	0,	0,	2,	0,	0,	0,	0,	0,	0,	2,	2,	0,	0,	0,	0,	2,	0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0},
       { 0,	0,	0,	0,	0,	2,	2,	0,	0,	0,	0,	2,	2,	0,	0,	0,	0,	0,	2,	0,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	0},
       { 0,	0,	0,	0,	0,	0,	0,	2,	2,	2,	2,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	0,	0,	0,	2,	2,	0,	0,	0,	0,	0},
       { 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	2,	2,	0,	0,	0,	0,	2,	2,	0,	0,	0,	0,	0},
       { 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	2,	2,	2,	2,	0,	0,	0,	0,	0,	0,	0}
    };
    int map3[18][32]{
        {3,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,},
        {0,	0,	3,	0,	0,	0,	0,	0,	1,	2,	1,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,},
        {0,	0,	0,	0,	0,	0,	0,	1,	2,	0,	1,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,},
        {3,	0,	3,	0,	3,	0,	0,	1,	2,	0,	1,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,},
        {0,	0,	0,	0,	0,	0,	1,	0,	0,	3,	0,	1,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,},
        {0,	0,	3,	0,	0,	0,	1,	2,	0,	0,	0,	1,	0,	0,	0,	0,	1,	0,	0,	0,	0,	2,	1,	0,	0,	0,	1,	0,	0,	0,	0,	0,},
        {0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	1,	0,	0,	0,	1,	0,	0,	0,	0,	0,	4,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,},
        {3,	0,	3,	0,	3,	0,	0,	1,	1,	0,	1,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,},
        {0,	0,	0,	0,	0,	0,	0,	0,	1,	2,	1,	0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,},
        {0,	0,	1,	1,	0,	0,	0,	0,	1,	0,	0,	1,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,},
        {0,	0,	1,	1,	0,	0,	0,	0,	1,	1,	0,	0,	2,	1,	0,	0,	0,	2,	1,	0,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,},
        {0,	0,	1,	1,	0,	0,	0,	0,	0,	1,	0,	0,	2,	0,	0,	0,	0,	0,	2,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,},
        {0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	1,	0,	2,	0,	0,	0,	2,	2,	0,	0,	0,	1,	0,	0,	0,	3,	0,	0,	0,	0,	0,	0,},
        {0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	1,	2,	0,	0,	0,	0,	0,	0,	0,	1,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,},
        {0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	0,	1,	1,	1,	0,	3,	0,	3,	0,	3,	0,	0,	0,	0,},
        {0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	0,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,},
        {0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	1,	0,	1,	0,	0,	0,	0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	0,},
        {0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	0,}

    };
    int map4[18][32]{
        {0,	0,	0,	4,	0,	0,	0,	0,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	0,	0,	4,	0,	0,	0,	0,	0,},
        {0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,},
        {0,	0,	0,	4,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	1,	1,	0,	0,	0,	0,	1,	0,	0,	0,	0,	1,	4,	0,	0,	0,	0,	0,},
        {0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	1,	0,	1,	1,	0,	1,	0,	0,	0,	1,	0,	1,	0,	0,	0,	0,	0,	0,},
        {0,	0,	0,	4,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	1,	0,	0,	0,	1,	0,	0,	1,	4,	0,	0,	0,	0,	0,},
        {0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	1,	2,	0,	0,	0,	1,	0,	0,	0,	1,	0,	0,	1,	0,	1,	0,	0,	0,	0,	0,	0,	0,},
        {0,	0,	0,	4,	0,	1,	0,	0,	0,	0,	2,	2,	0,	0,	0,	1,	0,	0,	0,	1,	0,	0,	1,	1,	0,	0,	4,	0,	0,	0,	0,	0,},
        {0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	2,	1,	0,	0,	1,	0,	0,	0,	0,	0,	1,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,},
        {0,	0,	0,	4,	0,	0,	0,	1,	1,	0,	0,	0,	0,	1,	0,	1,	0,	0,	0,	0,	1,	0,	1,	0,	0,	0,	4,	0,	0,	0,	0,	0,},
        {0,	0,	0,	0,	0,	0,	0,	1,	0,	1,	1,	1,	0,	0,	1,	0,	1,	0,	0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,},
        {0,	0,	0,	4,	0,	0,	0,	0,	1,	1,	0,	0,	0,	1,	0,	0,	0,	1,	0,	0,	1,	0,	0,	0,	0,	0,	4,	0,	0,	0,	0,	0,},
        {0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	1,	0,	0,	0,	1,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,},
        {0,	0,	0,	4,	0,	0,	0,	0,	0,	1,	0,	1,	0,	0,	1,	0,	1,	1,	0,	1,	0,	0,	0,	0,	0,	0,	4,	0,	0,	0,	0,	0,},
        {0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	1,	0,	0,	1,	1,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,},
        {0,	0,	0,	4,	0,	0,	0,	0,	0,	0,	1,	1,	0,	1,	1,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	4,	0,	0,	0,	0,	0,},
        {0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,},
        {0,	0,	0,	4,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	4,	0,	0,	0,	0,	0,},
        {0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,}
    };
    int map5[18][32]{
        {3,	0,	3,	0,	3,	0,	3,	0,	3,	0,	3,	0,	3,	0,	3,	0,	3,	0,	0,	0,	0,	3,	0,	3,	3,	0,	3,	0,	3,	0,	3,	0,},
        {0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	3,	3,	0,	0,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,},
        {3,	0,	3,	0,	3,	0,	3,	0,	3,	0,	3,	0,	3,	3,	0,	0,	0,	1,	3,	3,	0,	1,	3,	0,	3,	0,	3,	0,	3,	0,	3,	0,},
        {0,	0,	0,	0,	0,	0,	0,	0,	3,	0,	0,	3,	0,	0,	0,	1,	1,	1,	0,	0,	0,	1,	0,	0,	3,	0,	0,	0,	0,	0,	0,	0,},
        {3,	0,	3,	0,	3,	0,	3,	3,	0,	0,	3,	0,	0,	1,	1,	0,	1,	0,	1,	0,	1,	0,	1,	1,	0,	3,	3,	0,	3,	0,	3,	0,},
        {0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	1,	0,	0,	1,	3,	0,	1,	0,	1,	0,	3,	0,	1,	0,	0,	0,	0,	0,	0,	0,},
        {3,	0,	3,	0,	3,	0,	3,	0,	1,	0,	1,	1,	1,	0,	1,	3,	0,	0,	1,	3,	0,	1,	0,	3,	0,	1,	3,	0,	3,	0,	3,	0,},
        {0,	0,	0,	0,	0,	0,	3,	0,	1,	3,	0,	3,	0,	1,	1,	0,	0,	1,	3,	0,	3,	0,	1,	3,	0,	1,	0,	0,	0,	0,	0,	0,},
        {3,	0,	3,	0,	3,	3,	0,	0,	1,	0,	0,	0,	0,	3,	0,	1,	0,	1,	0,	0,	0,	0,	1,	0,	0,	1,	3,	0,	3,	0,	3,	0,},
        {0,	0,	0,	0,	0,	0,	0,	1,	3,	0,	3,	0,	3,	0,	3,	0,	1,	1,	1,	3,	0,	0,	1,	0,	1,	0,	0,	0,	0,	0,	0,	0,},
        {3,	0,	3,	0,	3,	0,	1,	1,	0,	0,	0,	0,	0,	3,	0,	3,	0,	0,	1,	0,	0,	1,	1,	1,	0,	1,	3,	0,	3,	0,	3,	0,},
        {0,	0,	0,	0,	0,	0,	1,	1,	3,	0,	3,	3,	0,	0,	0,	0,	0,	1,	0,	1,	1,	1,	0,	3,	0,	1,	0,	0,	0,	0,	0,	0,},
        {3,	0,	3,	0,	3,	0,	1,	3,	0,	3,	3,	0,	0,	1,	1,	3,	3,	0,	0,	0,	0,	0,	1,	0,	0,	1,	3,	0,	3,	0,	3,	0,},
        {0,	0,	0,	0,	0,	0,	1,	0,	3,	0,	3,	0,	1,	0,	2,	3,	0,	0,	1,	0,	1,	0,	1,	1,	1,	3,	0,	0,	0,	0,	0,	0,},
        {3,	0,	3,	0,	3,	3,	0,	1,	0,	0,	3,	0,	1,	2,	2,	0,	0,	1,	3,	3,	0,	1,	3,	0,	3,	0,	3,	0,	3,	0,	3,	0,},
        {0,	0,	0,	0,	0,	0,	3,	0,	1,	1,	0,	0,	0,	0,	0,	0,	1,	0,	3,	3,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,},
        {3,	0,	3,	0,	3,	0,	3,	0,	3,	0,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	1,	3,	0,	3,	0,	3,	0,	3,	0,	3,	0,},
        {0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,}

    };
};


#endif // MAINWINDOW_H

