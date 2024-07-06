#include "tank_s.h"

tank_s::tank_s(QWidget *parent) : QWidget(parent)
{

}
//位置设置
void tank_s:: LocationSetting(vector<vector<int>>&mainmap,vector<int>&ToolInfo,int direction){
    int a=200;
       if(!this->IsGood){a=300;}
     if(    mainmap[this->y][this->x]==250||
            mainmap[this->y+1][this->x]==250||
            mainmap[this->y][this->x+1]==250||
            mainmap[this->y+1][this->x+1]==250)
       {
         mainmap[ToolInfo[0]][ToolInfo[1]]=0;
         this->ToolType=ToolInfo[2];
         ToolInfo[0]=-1;
         ToolInfo[1]=-1;
         ToolInfo[2]=-1;
     }
       mainmap[this->y][this->x]=a+direction;
       mainmap[this->y+1][this->x]=a;
       mainmap[this->y][this->x+1]=a;
       mainmap[this->y+1][this->x+1]=a;
}

//设置坦克的新位置
void tank_s:: SetTankNewLocation(vector<vector<int>>&mainmap,vector<int>&ToolInfo,int direction){
    mainmap[this->y][this->x]=0;
    mainmap[this->y+1][this->x]=0;
    mainmap[this->y][this->x+1]=0;
    mainmap[this->y+1][this->x+1]=0;
    switch (direction) {
    case 1:
        this->y-=1;
        this->LocationSetting(mainmap,ToolInfo,1);
        break;
    case 2:
        this->y+=1;
        this->LocationSetting(mainmap,ToolInfo,2);
        break;
    case 3:
        this->x-=1;
        this->LocationSetting(mainmap,ToolInfo,3);
        break;
    case 4:
        this->x+=1;
        this->LocationSetting(mainmap,ToolInfo,4);
        break;
    default:
        break;
    }
}

//检查坦克能否移动
bool tank_s::checkTankIsMoveable(vector<vector<int>>&mainmap){
    if(this->direction==1)
    {   if(mainmap[this->y-1][this->x]!=0&&mainmap[this->y-1][this->x]!=250){return false;}
        if(mainmap[this->y-1][this->x+1]!=0&&mainmap[this->y-1][this->x+1]!=250){return false;}
    }
    if(this->direction==2){
        if(mainmap[this->y+2][this->x]!=0&&mainmap[this->y+2][this->x]!=250){return false;}
        if(mainmap[this->y+2][this->x+1]!=0&&mainmap[this->y+2][this->x+1]!=250){return false;}
    }
    if(this->direction==3){
        if(mainmap[this->y][this->x-1]!=0&&mainmap[this->y][this->x-1]!=250){return false;}
        if(mainmap[this->y+1][this->x-1]!=0&&mainmap[this->y+1][this->x-1]!=250){return false;}
    }
    if(this->direction==4){
        if(mainmap[this->y][this->x+2]!=0&&mainmap[this->y][this->x+2]!=250){return false;}
        if(mainmap[this->y+1][this->x+2]!=0&&mainmap[this->y+1][this->x+2]!=250){return false;}
    }
    return true;
}

//更新坦克的位置
void tank_s::update(vector<vector<int>>&mainmap,vector<int>&ToolInfo){
    switch (this->direction) {
    case 1:
        this->SetTankNewLocation(mainmap,ToolInfo,1);
        break;
    case 2:
        this->SetTankNewLocation(mainmap,ToolInfo,2);
        break;
    case 3:
        this->SetTankNewLocation(mainmap,ToolInfo,3);
        break;
    case 4:
        this->SetTankNewLocation(mainmap,ToolInfo,4);
        break;
    default:
        break;
    }
}
