#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QWidget>
#include<QGraphicsPixmapItem>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QList>
#include<QTimer>
#include<QtDebug>
#include<QKeyEvent>
#include"mytank.h"
#include"bullet.h"
#include"enemy.h"
#include"building.h"
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
    void changeMusic(int cnt);
    void boomEffect();
    void switch2main();
    void switch2w1();

private slots:
    void fromw2main();
    void switchOn();

private:
    Ui::MainWindow *ui;

    QGraphicsView mGameView;

    QGraphicsScene mScene;

    QGraphicsPixmapItem mBackGround;

    MyTank mTank;

    QTimer* BulletTime;

    QTimer* Time;

    QTimer* Time2;

    QTimer* GTime1;

    QTimer* GTime2;

    QTimer* GTime3;

    QTimer* GTime4;

    QTimer* GTime5;

    QTimer* GTime6;

    QList<Bullet*>mBullet;

    QList<Enemy*>mEnemy;

    QList<Heart*>mHeart;

    QList<Building*>mBuilding;

    QList<enemyBullet*>eBullet;

    QList<int>BulletMove;

    QList<BOSS*>mBoss;

    QList<BossBullet*>bBullet;


    int Ehp=2;

    int dir;

    int killnum;

    int grade;

    int hp;

    int mtankspeed;

    int Fire;

    int Death;

    int count=0;

    int KillNum;

    int accomplishment;

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

