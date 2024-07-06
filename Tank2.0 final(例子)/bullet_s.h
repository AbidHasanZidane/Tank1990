#ifndef BULLET_S_H
#define BULLET_S_H

#include <QWidget>
#include"tank_s.h"
class bullet_s : public QWidget
{
    Q_OBJECT
public:
    explicit bullet_s(QWidget *parent = nullptr);
    int x;
    int y;
    int direction;
    bool isHit=true;
    int HitsNum=0;
    QTimer*timer;
    bool update=true;
    bool isMine=false;
    void partBulletHitWall();
    void BulletHit();
    void init(tank_s* tank,int direction);
signals:

public slots:
};

#endif // BULLET_S_H
