/*
Author:qianmo
算法：数学
题目链接：https://www.luogu.com.cn/problem/P1029
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x0,y0;
    cin >> x0 >> y0;
    int a=x0*y0,ans=0;
    if(x0==y0) ans--;
    for(int i=1;i<=sqrt(a);i++)
        if(a%i==0&&__gcd(i,a/i)==x0) ans+=2;
    cout << ans;
    return 0;
}
