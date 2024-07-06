#include "bullet_s.h"
#include<QTimer>
bullet_s::bullet_s(QWidget *parent) : QWidget(parent)
{

}
//子弹击中可打碎的墙
void bullet_s::partBulletHitWall(){
    if(this->direction==1){this->direction=2;}
            else if(this->direction==2){this->direction=1;}
            else if(this->direction==3){this->direction=4;}
            else if(this->direction==4){this->direction=3;}
            ++this->HitsNum;
}

//子弹击中后停止的处理
void bullet_s::BulletHit(){
    this->timer->stop();
    this->isHit=true;
    this->x=0;
    this->y=0;
}

//初始化子弹
void bullet_s::init(tank_s* tank,int direction){
    if(direction==1)
    {
        this->x=tank->x*25+25;
        this->y=tank->y*25;
        if(this->isMine){this->x-=10;this->y-=20;}
    }
    if(direction==2)
    {
        this->x=tank->x*25+25;
        this->y=tank->y*25+50;
        if(this->isMine){this->x-=10;}
    }
    if(direction==3)
    {
        this->x=tank->x*25;
        this->y=tank->y*25+25;
        if(this->isMine){this->x-=20;this->y-=10;}
    }
    if(direction==4)
    {
        this->x=tank->x*25+50;
        this->y=tank->y*25+25;
        if(this->isMine){this->y-=10;}
    }
    this->isHit=false;
    this->direction=direction;
    this->HitsNum=0;
    this->timer=new QTimer(this);
    this->timer->start(5);
    this->update=false;
}
