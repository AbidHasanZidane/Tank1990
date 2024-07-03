#ifndef TANK_S_H
#define TANK_S_H
#include<vector>
#include<QSound>
#include<QPainter>
#include <QWidget>
using namespace std;

class tank_s : public QWidget
{
    Q_OBJECT
public:
    explicit tank_s(QWidget *parent = nullptr);
    int x;//tank located col
    int y;//tank located row
    int direction; //tank 方向  上下左右。
    bool isInit=false;
    bool alive=true;//是否生存
    bool IsGood=true;
    bool DieOnce=false;
    bool ShieldOn=false;
    bool LaserOn=false;
    int ToolType=-1;
    void SetTankNewLocation(vector<vector<int>>&mainmap,vector<int>&ToolInfo,int direction);
    void LocationSetting(vector<vector<int>>&mainmap,vector<int>&ToolInfo,int direction);
    bool checkTankIsMoveable(vector<vector<int>>&mainmap);
    void update(vector<vector<int>>&mainmap,vector<int>&ToolInfo);

signals:

public slots:
};

#endif // TANK_S_H
