// Date: 2021-10-19 09:16:02
// Problem: P1219 [USACO1.5]八皇后 Checker Challenge
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1219
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Stauts: ACcept 483ms
// Author: Guan Yongjie

#define DEBUG 1 //调试开关
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream> //个人不建议采用头文件，可能和定义的变量或名字起冲突，从而引起编译错误；
using namespace std;
int a[100], b[100], c[100], d[100];
// a数组表示的是行；
// b数组表示的是列；
// c表示的是左下到右上的对角线；
// d表示的是左上到右下的对角线；
int total; //总数:记录解的总数
int n;     //输入的数，即N*N的格子，全局变量，搜索中要用

void queen(int i) //搜索与回溯主体
{
    if (i > n)
    {
        if (total <= 2) //保证只输出前三个解，如果解超出三个就不再输出，但后面的total还需要继续叠加
        {
            for (int k = 1; k <= n; k++)
                cout << a[k] << " "; // for语句输出
            cout << endl;
        }
        total++; // total既是总数，也是前三个排列的判断
        return;
    }
    else
    {
        for (int j = 1; j <= n; j++) //尝试可能的位置
        {
            if ((!b[j]) && (!c[i + j]) && (!d[i - j + n])) //如果没有皇后占领，执行以下程序
            {
                a[i] = j; //标记i排是第j个
                b[j] = 1; //宣布占领纵列
                c[i + j] = 1;
                d[i - j + n] = 1;
                //宣布占领两条对角线
                queen(i + 1); //进一步搜索，下一个皇后
                b[j] = 0;
                c[i + j] = 0;
                d[i - j + n] = 0;
                //（回到上一步）清除标记
            }
        }
    }
}
int main()
{
    cin >> n;      //输入N*N网格，n已在全局中定义
    queen(1);      //第一个皇后
    cout << total; //输出可能的总数
    return 0;
}
