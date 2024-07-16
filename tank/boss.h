#ifndef BOSS_H
#define BOSS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>  // 包含QObject类的头文件，以便继承

class BOSS : public QGraphicsPixmapItem, public QObject
{
public:
    BOSS(int x, int y);  // 构造函数声明，用于初始化BOSS对象
    int bossSpeed = 10;  // BOSS的移动速度
    int BossHp = 50;  // BOSS的血量
};

#endif // BOSS_H
