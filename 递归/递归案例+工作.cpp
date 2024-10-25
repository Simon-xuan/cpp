#include <iostream>
using namespace std;


int q[5][5] = {//工资，每一列为每份工作
    {13, 11, 10, 4, 7},
    {13, 10, 10, 8, 5},
    {5, 9, 7, 7, 4},
    {15, 12, 10, 11, 5},
    {10, 11, 8, 8, 4}
};

int Max = -1;//最大值
int assignment[5]; // 存储工作分配结果 已有人为“1”，反之为0

void search(int,int);//因为主函数在定义函数的前面，所以要写，让系统知道代码在主程序的后面

int main()
{
    search(0, 0);
    cout << endl<<Max<<endl;
    return 0;
}

void search(int person, int sum)//无返回值函数
{
    if (person == 5)//当5个人都遍历完就可以判断最大值
    {
        // 已经遍历完所有人，更新最大工资
        if (sum > Max)
            Max = sum;
        return;
    }

    for (int job = 0; job < 5; job++)
    {
        if (assignment[person] == 0)//如果flag为1，说明这项工作已有人做了
        {
            assignment[person] = job + 1; // 标记当前人分配的工作
            search(person + 1, sum + q[person][job]); // 递归调用下一个人的分配
            assignment[person] = 0; // 取消当前人的工作分配标记，以便尝试其他工作
        }
    }
}
