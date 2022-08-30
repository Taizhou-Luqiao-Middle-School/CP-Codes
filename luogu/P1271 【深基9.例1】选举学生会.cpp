/*
Author:qianmo
算法：排序
题目链接：https://www.luogu.com.cn/problem/P1271
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    int a[m];
    for(int i=0;i<m;i++) cin >> a[i];
    sort(a,a+m);
    for(int i=0;i<m;i++) cout << a[i] << " ";
    return 0;
}