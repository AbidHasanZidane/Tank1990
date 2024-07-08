#include "tank_s.h"

tank_s::tank_s()
{

}
void tank_s::setNewlocation(vector<vector<int> > map)
{
    switch(direction){
    case 1:{//向左运动
        if(map[x-1][y]==0&&map[x-1][y+1]==0)//遇到空地
        {x=x-1;direction=1;}
        else if(map[x-1][y]==1||map[x-1][y+1]==1)//遇到刚墙
        {direction=2;}
        else if(map[x-1][y]==2||map[x-1][y+1]==2)//遇到砖头
        {direction=2;}
        else if(map[x-1][y]==3||map[x-1][y+1]==3)//遇到河流
        {direction=2;}
        else if(map[x-1][y]==4||map[x-1][y+1]==4)//遇到树
        {
            x=x-1;
            direction=1;
            layertank.setPos(x-1,y);
        }
    }
    case 2:{//向右运动
        if(map[x+2][y]==0&&map[x+2][y+1]==0)//遇到空地
        {x=x+1;direction=2;}
        else if(map[x+2][y]==1||map[x+2][y+1]==1)//遇到刚墙
        {direction=1;}
        else if(map[x+2][y]==2||map[x+2][y+1]==2)//遇到砖头
        {direction=1;}
        else if(map[x+2][y]==3||map[x+2][y+1]==3)//遇到河流
        {direction=1;}
        else if(map[x+2][y]==4||map[x+2][y+1]==4)//遇到树
        {
            x=x+1;
            direction=2;
            layertank.setPos(x+1,y);
        }
    }
    case 3:{//向上运动
        if(map[x][y+2]==0&&map[x+1][y+2]==0)//遇到空地
        {y=y+1;direction=3;}
        else if(map[x][y+2]==1||map[x+1][y+2]==1)//遇到刚墙
        {direction=4;}
        else if(map[x][y+2]==2||map[x+1][y+2]==2)//遇到砖头
        {direction=4;}
        else if(map[x][y+2]==3||map[x+1][y+2]==3)//遇到河流
        {direction=4;}
        else if(map[x][y+2]==4||map[x+1][y+2]==4)//遇到树
        {
            y=y+1;
            direction=3;
            layertank.setPos(x,y+1);
        }
    }
    case 4:{//向下运动
        if(map[x][y-1]==0&&map[x+1][y-1]==0)//遇到空地
        {y=y-1;direction=4;}
        else if(map[x][y-1]==1||map[x+1][y-1]==1)//遇到刚墙
        {direction=3;}
        else if(map[x][y-1]==2||map[x+1][y-1]==2)//遇到砖头
        {direction=3;}
        else if(map[x][y-1]==3||map[x+1][y-1]==3)//遇到河流
        {direction=3;}
        else if(map[x][y-1]==4||map[x+1][y-1]==4)//遇到树
        {
            y=y-1;
            direction=4;
            layertank.setPos(x,y-1);
        }
    }
    }
}
