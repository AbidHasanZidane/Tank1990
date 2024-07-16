#ifndef HEART_H
#define HEART_H

#include <QGraphicsPixmapItem> 
#include <QGraphicsItem>     
#include <QObject>        

// 定义Heart类，继承自QGraphicsPixmapItem和QObject
class Heart: public QGraphicsPixmapItem, public QObject
{
public:
    // 构造函数，接受x和y坐标参数，用于初始化Heart对象
    Heart(int x, int y);
};

#endif // HEART_H
