#ifndef TANK_S_H
#define TANK_S_H
#include<iostream>
#include<QPainter>
#include<vector>
#include <QApplication>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QVBoxLayout>

using namespace std;


class tank_s:public QWidget
{
    Q_OBJECT
public:
    tank_s();
    int x;
    int y;//坦克位置（坦克占2*2位置，取左下角）
    int direction;//移动方向，左1右2上3下4
    void setNewlocation(vector<vector<int>> &mainmap);//



};

#endif // TANK_S_H
