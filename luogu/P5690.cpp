// Date: 2021-10-19 21:10:12
// Problem: P5690 [CSP-S2019 江西] 日期
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5690
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Stauts: ACcept 21ms
// Author: Guan Yongjie

#define DEBUG 1  //调试开关
#include<bits/stdc++.h>
using namespace std;
int m,d;
int main()
{
    scanf("%d-%d",&m,&d);
    if(d>0&&d<=28)
    {
        if(m>0&&m<=12)cout<<0; //肯定合法
        else cout<<1;
    }
    else if(d==29||d==30)
    {
        if(m==2||m==0||m>12)cout<<1;
        else cout<<0;
    }
    else if(d==31)
    {
        if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)cout<<0;
        else if(m==2||m==4||m==6||m==9||m==11||m==14)cout<<1;
        else if(m%10==4||m%10==6||m%10==9)cout<<2;
        else cout<<1;
    }
    else if(m==0||m>12)cout<<2;
    else cout<<1;
} 
