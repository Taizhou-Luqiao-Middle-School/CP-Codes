// Date: 2022-07-20 10:43:42
// Problem: 方程的解
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1310/
// Memory Limit: 128 MB
// Time Limit: 1000 ms

// Author: Codeboy

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 150, mod = 1000;

int k, x;
int f[1000][100][N];

int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void add(int a[N], int b[N], int c[N])
{
    for (int i = 0, t = 0; i < N; i++)
    {
        t += b[i] + c[i];
        a[i] = t % 10;
        t /= 10;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> k >> x;
    int n = qpow(x % mod, x);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i && j < k; j++)
        {
            if (!j)
                f[i][j][0] = 1;
            else
                add(f[i][j], f[i - 1][j], f[i - 1][j - 1]);
        }
    }

    int iter = N - 1;
    while (!f[n - 1][k - 1][iter])
        --iter;
    while (iter >= 0)
        cout << f[n - 1][k - 1][iter--];
    return 0;
}
