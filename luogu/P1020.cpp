// Date: 2021-10-18 17:14:13
// Problem: P1020 [NOIP1999 普及组] 导弹拦截
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1020
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Stauts: ACcept 319ms
// Author: Guan Yongjie

#define DEBUG 1  //调试开关
#include <bits/stdc++.h>
using namespace std;
int f[1000000];
int z[1000000];
int lowbit(int x)
{
    return x&-x;
}
int big;
inline int ask(int x)//求单调上升子序列
{
    int r=0;
    for(int i=x;i>0;i-=lowbit(i))
        r=max(r,f[i]);
    return r;
}
inline void add(int x,int v)//求单调上升子序列
{
    for(int i=x;i<=big;i+=lowbit(i))
        f[i]=max(f[i],v);
}
inline int que(int x)//求最长单调不升子序列
{
    int r=0;
    for(int i=x;i<=big;i+=lowbit(i))
        r=max(r,f[i]);
    return r;
}
inline void psh(int x,int v)//求最长单调不升子序列
{
    for(int i=x;i>0;i-=lowbit(i))
        f[i]=max(f[i],v);
}
int tot;
int a[1000000];
int ans;
int main()
{
    tot=1;
    while(scanf("%d",&a[tot])!=EOF)
    {
        big=max(big,a[tot]);
        z[tot]=a[tot];
        tot++;
    }
    tot--;//读入并统计个数
    for(int i=1;i<=tot;i++)//求最长单升子序列，树状数组中保存的是0~a[i]的最大值
    {
        int x=ask(a[i])+1;
        ans=max(ans,x);
        add(a[i]+1,x);//因为是严格单升所以这里要+1
    }
    memset(f,0,sizeof(f));//清空树状数组，用来求下面的不降子序列
    int num=0;
    for(int i=1;i<=tot;i++)//求最长不降子序列，树状数组里存的是a[i]~inf的最大值
    {
        int x=que(a[i])+1;
        num=max(num,x);
        psh(a[i],x);//因为是不升而不是严格单降所以不用-1或+1
    }
    printf("%d\n%d",num,ans);
    return 0;
}