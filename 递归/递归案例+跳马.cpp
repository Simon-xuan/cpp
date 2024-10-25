#include<iostream>
using namespace std;
int flag[5][5];//用于标记第几次和是否被占用。没有占用为-1。输出时加一
int sum=1;//次数
void chu(){
    for(int i=0;i<5;i++) //0到4下标
    {
        for(int j=0;j<5;j++)
        {
            flag[i][j]=-1;
        }
    }
}
void pr();

int x1[8]={2,2,1,1,-2,-2,-1,-1};//x移动坐标
int y1[8]={1,-1,2,-2,1,-1,2,-2};//y移动坐标

int f(int x,int y)
{
    for(int i=0;i<8;i++)
    {
        //判断条件分别是：1.没有被占用 2.没有超出边界
        if(flag[x+x1[i]][y+y1[i]]==-1 && x+x1[i]>=0 && x+x1[i]<=4 && y+y1[i]>=0 && y+y1[i]<=4)
        {
            flag[x+x1[i]][y+y1[i]]=sum;
            sum++;
            if(sum==25) {pr(); sum=1;}y7 
            else f(x+x1[i],y+y1[i]);
            flag[x+x1[i]][y+y1[i]]=-1;
        }
    }
}


void pr(){
    for(int i=0;i<5;i++)
    {
        for(int x=0;x<5;x++)
        {
            cout<<flag[i][x]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    chu();
    f(0,0);
    
}