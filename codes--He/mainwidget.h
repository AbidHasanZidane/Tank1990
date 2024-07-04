#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <iostream>
#include <QString>
#include <vector>
#include <iterator>

using namespace std;

QGraphicsScene scene;//创建一个所有图形元素的容器
class space//空地
{
public:
    int x,y;
    int attribute;
    QGraphicsRectItem layerSpace;//空地图层
    space(int dx,int dy):x(dx),y(dy)
    {
        attribute=0;
        layerSpace.setPos(dx,dy);//设置位置

    }
};


class unbitWall//刚墙
{
public:
    int x,y;
    int attribute;
    QGraphicsRectItem layerUbw;//刚墙图层
    unbitWall(int dx,int dy):x(dx),y(dy)
    {
        attribute=1;
        layerUbw.setPos(dx,dy);//设置位置

    }

};

class bitWall//砖头
{
public:
    int x,y;
    int attribute;
    QGraphicsRectItem layerBw;//砖头图层
    bitWall(int dx,int dy):x(dx),y(dy)
    {
        attribute=2;
        layerBw.setPos(dx,dy);//设置位置

    }

};
class river//河流
{
public:
    int x,y;
    int attribute;
    QGraphicsRectItem layerriver;//河流图层
    river(int dx,int dy):x(dx),y(dy)
    {
        attribute=3;
        layerriver.setPos(dx,dy);//设置位置

    }
};

class tree//树
{
public:
    int x,y;
    int attribute;
    QGraphicsRectItem layertree;//树图层
    tree (int dx,int dy):x(dx),y(dy)
    {
        attribute=4;
        layertree.setPos(dx,dy);//设置位置

    }
};

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    //样例地图
    vector<vector<int>>forevermap ={
        //1表示不可摧毁，2可摧毁，0空地
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        //1
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,1},
        {1,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,1},
        //2
        {1,0,0,2,2,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,2,2,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,2,2,0,0,2,2,0,0,2,2,1,1,2,2,0,0,2,2,0,0,2,2,0,0,1},
        {1,0,0,2,2,0,0,2,2,0,0,2,2,1,1,2,2,0,0,2,2,0,0,2,2,0,0,1},
        //3
        {1,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,0,0,0,0,1},
        {1,0,0,2,2,0,0,2,2,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,1},
        {1,0,0,2,2,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        //4
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,1},
        {1,1,1,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,1,1,1},
        //5
        {1,0,0,0,0,0,0,0,0,0,0,2,2,0,0,2,2,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,2,2,0,0,2,2,0,0,2,2,2,2,2,2,0,0,2,2,0,0,0,0,0,0,1},
        //6
        {1,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,0,0,0,0,1},
        {1,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,0,0,0,0,1},
        {1,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,2,2,0,0,0,0,0,0,1},
        //7
        {1,0,0,2,2,0,0,2,2,0,0,0,0,0,0,0,0,0,0,2,2,0,0,2,2,0,0,1},
        {1,0,0,2,2,0,0,2,2,0,0,0,0,0,0,0,0,0,0,2,2,0,0,2,2,0,0,1},
        //8
        {1,0,0,2,2,0,0,2,2,0,0,2,2,2,2,2,2,0,0,2,2,0,0,2,2,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2,2,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2,2,0,0,0,0,0,0,0,0,0,0,1},
        //
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

   // void paintEvent(QPaintEvent *event);
    ~MainWidget();

private:
    Ui::MainWidget *ui;
};

#endif // MAINWIDGET_H
