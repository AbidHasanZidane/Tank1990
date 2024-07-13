#ifndef BOSS_H
#define BOSS_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include<QObject>

class BOSS : public QGraphicsPixmapItem,public QObject
{
public:
    BOSS(int x,int y);
    int bossSpeed=10;
    int BossHp=50;
};

#endif // BOSS_H
