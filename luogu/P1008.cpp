// Date: 2021-10-18 19:39:10
// Problem: P1008 [NOIP1998 普及组] 三连击
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1008
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Stauts: ACcept
// Author: Guan Yongjie

#include<cstdio>
#include<cstring>
int i,j,v;bool a[10];//ai表示第i个数已经用过了
int main()
{
    for(i=192;i<=327;i++)//第一个数最小192，最大327。其实不知道的情况下简单来说是从123-329的但是算出来是最值就稍微改了下下
    {
        memset(a,0,sizeof(a));v=0;//清零
        a[i%10]=a[i/10%10]=a[i/100]=a[i*2%10]=a[i*2/10%10]=a[i*2/100]=a[i*3%10]=a[i*3/10%10]=a[i*3/100]=1;//统计数字
        for(j=1;j<=9;j++) v+=a[j];//v表示1-9这些数字是否全部齐了
        if(v==9) printf("%d %d %d\n",i,i*2,i*3);//如果齐了就输出
    }
return 0;
}
