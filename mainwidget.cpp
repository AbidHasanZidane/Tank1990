#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QPainter>
#include <QString>
#include <QBrush>
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>
#include <queue>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

static vector<vector<int> >mainmap ={
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
    {1,1,1,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,1,1,1}

};

static vector<vector<int> >tempmap=mainmap;

MainWidget::MainWidget(QWidget *parent) :QWidget(parent),ui(new Ui::MainWidget)
{
    //初始化地图
    initScene();

    mainmap=forevermap;
    tempmap=forevermap;
    //创建一个QGraphicsScene
    QGraphicsScene *scene = new QGraphicsScene(this);

    //创建一个QGraphicsView并将scene设置为其场景
    QGraphicsView *view = new QGraphicsView(scene, this);
    view->setFixedSize(1280, 720); // 设置固定大小
    scene->setSceneRect(0, 0, 1280, 720);

    // 障碍物图标文件路径
        QString emptyPath = ":/new/prefix1/wallimage/space.png";
        QString steelWallPath = ":/new/prefix1/wallimage/unbitWall.png";
        QString brickWallPath = ":/new/prefix1/wallimage/bitWall.png";
        QString riverPath = ":/new/prefix1/wallimage/river.png";
        QString grassPath = ":/new/prefix1/wallimage/tree.png";

        // 遍历mainmap数组并在scene中初始化地图
            for (int i = 0; i < 28; ++i) {
                for (int j = 0; j < 16; ++j) {
                    QGraphicsPixmapItem *item = nullptr;
                    switch (mainmap[i][j]) {
                        case 0:
                            item = new QGraphicsPixmapItem(QPixmap(emptyPath));
                            break;
                        case 1:
                            item = new QGraphicsPixmapItem(QPixmap(steelWallPath));
                            break;
                        case 2:
                            item = new QGraphicsPixmapItem(QPixmap(brickWallPath));
                            break;
                        case 3:
                            item = new QGraphicsPixmapItem(QPixmap(riverPath));
                            break;
                        case 4:
                            item = new QGraphicsPixmapItem(QPixmap(grassPath));
                            break;
                    default:
                        break;
                    }
                    if (item) {
                        item->setPos(j * 45, i * 45); // 设置位置,假设每个格子大小为45*45
                        scene->addItem(item);
                    }
                }
            }

            // 将view添加到布局中
               QVBoxLayout *layout = new QVBoxLayout(this);
               layout->addWidget(view);
               setLayout(layout);

}

void MainWidget::initScene()
{
    //初始化窗口大小
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置窗口标题
    setWindowTitle(GAME_TITLE);
}

MainWidget::~MainWidget()
{
    delete ui;
}



