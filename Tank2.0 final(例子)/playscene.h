#ifndef PLAYSCENE_H
#define PLAYSCENE_H
#include <QMainWindow>
#include<vector>
#include"mypushbutton.h"
#include"tank_s.h"
#include"bullet_s.h"
using namespace std;
struct point{
    int x;
    int y;
    int step;
};

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = nullptr);
    /**********************************/
    vector<vector<int>>forevermap={
        // 1表示不能打碎的墙 2表示可以打碎的墙
        //1
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,2,2,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
        //2
        {1,0,0,2,0,0,0,0,0,1,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
        {1,0,0,2,0,0,0,0,0,1,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,2,0,0,0,0,0,1,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,2,2,2,0,0,0,0,0,1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        //3
        {1,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        //4
        {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
        //5
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
        //6
        {1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
        //7
        {1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        //8
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };
    void paintEvent(QPaintEvent *event);
    vector<int> CreateRandomPosAndTool();

    void initMy_Tank();
    void initEnemy_Tank();
    void initBullet(tank_s* tank,bullet_s*bullet,int direction);
    void BulletHitWall(bullet_s*bullet,int x,int y);
    void paintBullet(bullet_s*bullet);
    void paintMine(bullet_s*mine);
    void BulletHitTank(tank_s*tank,bullet_s*bullet);
    void MineHitTank(tank_s*tank,bullet_s*mine);
    void DeathEffect(tank_s*tank);
    void GameOver();
    void PaintLaserIsHit(tank_s*tank);

    void EnemyTankMove();
    void EnemyFire();
    void ShootBulletE();
    void DodgeBullet(bullet_s*bullet);
    void Dodge();
    bool CheckAheadBullet(bullet_s*bullet,int direction);

    vector<int>ToolInfo{-1,-1,-1};
    bool IsGameOver=false;
    QTimer*movespeed;
    QTimer*movespeed2;
    bool SpeedControl=true;
    bool SpeedControl2=true;
    MyPushButton*backBtn;
    MyPushButton*playBtn;
    bool Btnmove=false;
    QTimer*PopOutTool;
    QTimer*IsOver;
    QTimer*riverflow;
    bool isOver=false;
    bool isPlaced=false;
    bool river1=true;

    vector<int>res;
    int num;    
    QTimer*reroute;
    QTimer*EnemyTimer;
    QTimer*DodgeTimer;
    vector<int>BFS(vector<vector<int>>tempmap);    

    /**********************************/
signals:
   void playSceneBack();
   void playSceneAgain();
public slots:

private:
    void keyPressEvent(QKeyEvent *event);
    tank_s* my_tank=new tank_s(this);
    bullet_s*bullet1=new bullet_s(this);
    bullet_s*bullet2=new bullet_s(this);
    bullet_s*bullet3=new bullet_s(this);
    tank_s* enemy_tank=new tank_s(this);
    bullet_s*bullet1E=new bullet_s(this);
    bullet_s*bullet2E=new bullet_s(this);
    bullet_s*bullet3E=new bullet_s(this);
    bullet_s*Mine=new bullet_s(this);

};

#endif // PLAYSCENE_H
