// Date: 2021-10-18 15:16:45
// Problem: P1003 [NOIP2011 提高组] 铺地毯
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1003
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Stauts: ACcept
// Author: Guan Yongjie

#define DEBUG 1  //调试开关
#include<iostream>
using namespace std;

int a[100001],b[100001],g[100001],k[100001],x,y,n;

int main()
{
    ios::sync_with_stdio(false);
    
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>g[i]>>k[i];
    }
    cin>>x>>y;
    bool flag=false;
    for(int i=n;i>=1;i--)
    {
        if((a[i]+g[i])>=x && a[i]<=x && (b[i]+k[i])>=y && b[i]<=y)
        {
            cout<<i;
            flag=1;
            break;
        }
    }
    if(!flag){cout<< -1;};
}

/*
改陈年90pts代码，秒过
*/