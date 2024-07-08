#include "tank_s.h"

tank_s::tank_s()
{

}
void tank_s::setNewlocation(vector<vector<int>>& mainmap) {
    int newX = x;
    int newY = y;

    // 根据当前方向计算新的坐标
    switch (direction) {
        case 1: // 向左
            newX -= 1;
            break;
        case 2: // 向右
            newX += 1;
            break;
        case 3: // 向上
            newY -= 1;
            break;
        case 4: // 向下
            newY += 1;
            break;
        default:
            return; // 如果方向不正确，直接返回
    }
    QGraphicsScene *scene = new QGraphicsScene(this);
    QGraphicsPixmapItem *item = nullptr;

    // 障碍物图标文件路径
        QString emptyPath = ":/new/prefix1/wallimage/space.png";
        QString steelWallPath = ":/new/prefix1/wallimage/unbitWall.png";
        QString brickWallPath = ":/new/prefix1/wallimage/bitWall.png";
        QString riverPath = ":/new/prefix1/wallimage/river.png";
        QString grassPath = ":/new/prefix1/wallimage/tree.png";
        QString tankPath=":/new/prefix1/wallimage/tank.png";

    // 检查新的位置是否在地图范围内，以及是否有障碍物
    if (newX >= 0 && newY >= 0 && newX + 1 < mainmap[0].size() && newY + 1 < mainmap.size()) {
        bool canMove = true;
        bool istree = false;//判断是否有草丛
        // 检查坦克占据的2*2区域是否有障碍物
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if(mainmap[newX][newY]!=0&&mainmap[newX][newY]!=4)
                {
                    canMove=false;
                    break;
                }
            }
        }
        // 如果新的位置有障碍物
        if (!canMove) {
            item = new QGraphicsPixmapItem(QPixmap(tankPath));
            item->setPos(x * 38*2, y * 38*2); // 设置位置
            scene->addItem(item);
        }else//没有再判断是否有草丛
        {
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    if(mainmap[newX][newY]==4)
                    {
                        istree=true;
                        break;
                    }
                }
            }
            if(istree){//有草丛则覆盖坦克
                x=newX;
                y=newY;//更新位置
                item = new QGraphicsPixmapItem(QPixmap(tankPath));
                item->setPos(x * 38*2, y * 38*2); // 设置位置
                scene->addItem(item);
                item = new QGraphicsPixmapItem(QPixmap(grassPath));
                item->setPos(x * 38, y * 38); // 设置位置
                scene->addItem(item);
            }
            else {//没有则坦克覆盖空地
                x=newX;
                y=newY;//更新位置
                item = new QGraphicsPixmapItem(QPixmap(emptyPath));
                item->setPos(x * 38, y * 38); // 设置位置
                scene->addItem(item);
                item = new QGraphicsPixmapItem(QPixmap(tankPath));
                item->setPos(x * 38*2, y * 38*2); // 设置位置
                scene->addItem(item);
            }

        }
    }
}
