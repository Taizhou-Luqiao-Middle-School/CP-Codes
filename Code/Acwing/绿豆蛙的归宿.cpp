#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 200010;

int n, m;
int h[N], e[M], w[M], ne[M], idx;
int dout[N];
double f[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

double dp(int u)
{
    if (f[u] >= 0)
        return f[u];
    f[u] = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        f[u] += (w[i] + dp(j)) / dout[u];
    }
    return f[u];
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        dout[a]++;
    }

    memset(f, -1, sizeof f);

    printf("%.2lf\n", dp(1));

    return 0;
}