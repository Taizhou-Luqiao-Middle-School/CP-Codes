// Date: 2021-10-19 21:01:22
// Problem: P2615 [NOIP2015 提高组] 神奇的幻方
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2615
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Stauts: ACcept 20ms
// Author: Guan Yongjie

#include <cstdio>
using namespace std;
int n, a[10010][10010], x = 1, y, cnt = 2;
int main()
{
    scanf("%d", &n);
    y = (n + 1) / 2;
    a[x][y] = 1;
    int now = n * n;
    for (int i = 2; i <= now; ++i)
    {
        if (x == 1 && y != n)
        {
            a[n][y + 1] = cnt;
            x = n;
            y += 1;
            cnt++;
        }
        else if (x != 1 && y == n)
        {
            a[x - 1][1] = cnt;
            x -= 1;
            y = 1;
            cnt++;
        }
        else if (x == 1 && y == n)
        {
            a[x + 1][y] = cnt;
            x += 1;
            cnt++;
        }
        else
        {
            if (a[x - 1][y + 1] == 0)
            {
                a[x - 1][y + 1] = cnt;
                x -= 1;
                y += 1;
                cnt++;
            }
            else
            {
                a[x + 1][y] = cnt;
                x += 1;
                cnt++;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int e = 1; e <= n; ++e)
            printf("%d ", a[i][e]);
        printf("\n");
    }
    return 0;
}
