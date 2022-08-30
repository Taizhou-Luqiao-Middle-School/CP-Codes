// Date: 2021-10-19 08:07:40
// Problem: P3475 [POI2008]POD-Subdivision of Kingdom
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3475
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Stauts: ACcept 2.91s
// Author: Guan Yongjie

// 模拟退火玄学算法
#define DEBUG 1  //调试开关
#include <bits/stdc++.h>
#define EPS 1e-14
#define pd(x, y) ((pos[(x)] > mid) ^ (pos[(y)] > mid))
using namespace std;
double T, delT = 0.996;
int a[300], pos[300], s[300], fr[3000], to[3000];
int n, m, mid;
int main()
{
    cin >> n >> m;
    mid = n / 2;
    for(int i = 1; i <= n; i++)
        a[i] = pos[i] = i;
    for(int i = 1; i <= n / 2; i++)
        s[i] = i;
    int ans = 0;
    for(int i = 1; i <= m; i++)
    {
        cin >> fr[i] >> to[i];
        if(pd(fr[i], to[i])) ans++;
    }
    srand(time(NULL));
    int tim = 30;
    while(tim--)
    {
        for(T = 100000; T > EPS; T *= delT)
        {
           printf("%.17f\n", T);
            int x = rand() % mid + 1;
            int y = rand() % mid + mid + 1;
            swap(a[x], a[y]);
            swap(pos[a[x]], pos[a[y]]);
            int now = 0;
            for(int i = 1; i <= m; i++)
            {
                if(pd(fr[i], to[i]))
                    now++;
            }
            if(now < ans)
            {
                ans = now;
                for(int i = 1; i <= n / 2; i++)
                {
                    s[i] = a[i];
                }
            }
            else if(exp((ans - now) / T) * RAND_MAX <= rand())
            {
                swap(a[x], a[y]);
                swap(pos[a[x]], pos[a[y]]);
            }
        }
    }
    sort(s + 1, s + n / 2 + 1);
    for(int i = 1; i <= n / 2; i++)
    {
        cout << s[i] << ' ';
    }
    return 0;
}



