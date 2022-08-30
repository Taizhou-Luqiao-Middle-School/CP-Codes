#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
using namespace std;
#define mod 998244353
#define ll long long
int dp[2][2][305][70][305], n, m, k, K, g[305][305][305][2], h[305][305][2], f[305], inv struct data
{
    int dp[3][3];
    data()
    {
        memset(dp, 0, sizeof(dp));
    }
    friend bool operator<(const data a, const data b)
    {
        for (int i = 0; i <= 2; i++)
        {
            for (int t = 0; t <= 2; t++)
            {
                if (a.dp[i][t] != b.dp[i][t])
                {
                    return a.dp[i][t] < b.dp[i][t];
                }
            }
        }
        return 0;
    }
    friend bool operator!=(const data a, const data b)
    {
        for (int i = 0; i <= 2; i++)
        {
            for (int t = 0; t <= 2; t++)
            {
                if (a.dp[i][t] != b.dp[i][t])
                {
                    return 1;
                }
            }
        }
        return 0;
    }
    void DP(data &c, int del)
    {
        for (int i = 0; i <= 2; i++)
        {
            for (int t = 0; t <= 2; t++)
            {
                if (dp[i][t])
                {
                    if (del >= i + t)
                    {
                        c.dp[t][(del - i - t) % 3] |= 1;
                    }
                }
            }
        }
    }
};
struct node
{
    data is_pair[2];
    void clear()
    {
        is_pair[0] = data();
        is_pair[1] = data();
    }
    friend bool operator<(const node a, const node b)
    {
        if (a.is_pair[0] != b.is_pair[0])
        {
            return a.is_pair[0] < b.is_pair[0];
        }
        if (a.is_pair[1] != b.is_pair[1])
        {
            return a.is_pair[1] < b.is_pair[1];
        }
        return 0;
    }
    friend node operator+(node a, int b)
    {
        node c;
        if (b >= 2)
        {
            a.is_pair[0].DP(c.is_pair[1], b - 2);
        }
        a.is_pair[0].DP(c.is_pair[0], b);
        a.is_pair[1].DP(c.is_pair[1], b);
        return c;
    }
} st, sav[205];
map<node, int> mp;
int tot, c[200005][25];
void bfs()
{
    queue<node> q;
    st.clear();
    st.is_pair[0].dp[0][0] = 1;
    q.push(st);
    mp[st] = ++tot;
    sav[tot] = st;
    len[tot] = 0;
    while (!q.empty())
    {
        node x = q.front();
        q.pop();
        int now = mp[x];
        for (int i = 1; i <= 4; i++)
        {
            node nex = x + i;
            if (mp[nex])
            {
                c[now][i] = mp[nex];
            }
            else
            {
                mp[nex] = ++tot, c[now][i] = tot, q.push(nex), sav[tot] = nex, len[tot]
            }
        }
    }
}
int add(int x)
{
    return x >= mod ? x - mod : x;
}
int ksm(int x, int y)
{
    int ans = 1, t = x;
    while (y)
    {
        if (y & 1)
        {
            ans = 1ll * ans * t % mod;
        }
        t = 1ll * t * t % mod;
        y >>= 1;
    }
    return ans;
}
int C(int n, int m)
{
    if (n < m || m < 0)
    {
        return 0;
    }
    return 1ll * f[n] * inv[n - m] % mod * inv[m] % mod;
}
int main()
{
    freopen("mahjong.in", "r", stdin);
    freopen("mahjong.out", "w", stdout);
    bfs();
    dp[0][0][0][1][0] = g[0][0][0][0] = 1;
    scanf("%d%d%d", &n, &m, &k);
    K = 3 * k + 2;
    for (int s = 0; s <= k; s++)
    {
        nex ^= 1;
        for (int i = 0; i <= K; i++)
        {
            int qwq = min(4 * i, K);
            for (int j = 1; j <= tot; j++)
            {
                for (int t = i - i % 3 + len[j]; t <= qwq; t += 3)
                {
                    dp[nex][0][i][j][t] = 0;
                }
            }
            for (int j = 1; j <= tot; j++)
            {
                for (int t = i - i % 3 + (len[j] + 2) % 3; t <= qwq; t += 3)
                {
                    dp[nex][1][i][j][t] = 0;
                }
            }
        }
        for (int i = 0; i <= K; i++)
        {
            int qwq = min(4 * i, K);
            for (int t = 0; t <= qwq; t++)
            {
                g[s + 1][i][t][0] = mod - dp[nex ^ 1][0][i][1][t];
                g[s + 1][i][t][1] = mod - dp[nex ^ 1][1][i][1][t];
            }
        }
        for (int i = 0; i < K; i++)
        {
            int qwq = min(4 * i, K - 1);
            for (int j = 1; j <= tot; j++)
            {
                for (int t = i - i % 3 + len[j]; t <= qwq; t += 3)
                {
                    if (!dp[nex ^ 1][0][i][j][t])
                    {
                        continue;
                    }
dp[nex ^ 1][0][i + 1][c[j][1]][t + 1] = add(dp[nex ^ 1][0][i + 1][c
dp[nex ^ 1][0][i + 1][c[j][2]][t + 2] = add(dp[nex ^ 1][0][i + 1][c
dp[nex ^ 1][0][i + 1][c[j][3]][t + 3] = add(dp[nex ^ 1][0][i + 1][c
dp[nex ^ 1][0][i + 1][c[j][4]][t + 4] = add(dp[nex ^ 1][0][i + 1][c
                }
            }
        }
        for (int i = 0; i < K; i++)
        {
            int qwq = min(4 * i, K - 1);
            for (int j = 1; j <= tot; j++)
            {
                for (int t = i - i % 3 + (len[j] + 2) % 3; t <= qwq; t += 3)
                {
                    if (!dp[nex ^ 1][1][i][j][t])
                    {
                        continue;
                    }
dp[nex ^ 1][1][i + 1][c[j][1]][t + 1] = add(dp[nex ^ 1][1][i + 1][c
dp[nex ^ 1][1][i + 1][c[j][2]][t + 2] = add(dp[nex ^ 1][1][i + 1][c
dp[nex ^ 1][1][i + 1][c[j][3]][t + 3] = add(dp[nex ^ 1][1][i + 1][c
dp[nex ^ 1][1][i + 1][c[j][4]][t + 4] = add(dp[nex ^ 1][1][i + 1][c
                }
            }
        }
        for (int j = 1; j <= tot; j++)
        {
            if (sav[j].is_pair[0].dp[0][0])
            {
                for (int i = 0; i <= K; i++)
                {
                    int qwq = min(4 * i, K);
                    for (int t = i - i % 3; t <= qwq; t += 3)
                    {
dp[nex][0][i][1][t] = add(dp[nex][0][i][1][t] + dp[nex ^ 1][0][i
                    }
                    for (int t = i - i % 3 + 2; t <= qwq; t += 3)
                    {
dp[nex][1][i][1][t] = add(dp[nex][1][i][1][t] + dp[nex ^ 1][1][i
                    }
                }
            }
            if (sav[j].is_pair[1].dp[0][0])
            {
                for (int i = 0; i <= K; i++)
                {
                    int qwq = min(4 * i, K);
                    for (int t = i - i % 3 + 2; t <= qwq; t += 3)
                    {
dp[nex][1][i][1][t] = add(dp[nex][1][i][1][t] + dp[nex ^ 1][0][i
                    }
                }
            }
        }
        for (int i = 0; i <= K; i++)
        {
            int qwq = min(4 * i, K);
            for (int t = 0; t <= qwq; t++)
            {
g[s + 1][i][t][0] = dp[nex][0][i][1][t] = add(g[s + 1][i][t][0] + dp[nex
g[s + 1][i][t][1] = dp[nex][1][i][1][t] = add(g[s + 1][i][t][1] + dp[nex
            }
        }
    }
    f[0] = 1;
    for (int i = 1; i <= K; i++)
    {
        f[i] = 1ll * f[i - 1] * i % mod;
    }
    inv[K] = ksm(f[K], mod - 2);
    for (int i = K - 1; i >= 0; i--)
    {
        inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
    }
    for (int i = 0; i <= K; i++)
    {
        int now = n + 1 - i;
        if (now < 0)
        {
            break;
        }
for (int s = 1, w = now, res = now - 1; s <= k + 1; s++, w = 1ll * w * res % mod
for (int t = 0; t <= K; t++) {
            for (int q = 0; q <= 1; q++)
            {
                h[1][t][q] = (h[1][t][q] + 1ll * g[s][i][t][q] * w % mod * inv[s]) %
            }
}
    }
}
h[1][0][0] = 0;
for (int s = 1; s <= k; s++)
{
    for (int i = 0; i <= K; i++)
    {
        for (int q = 0; q <= 1; q++)
        {
            for (int j = 0; i + j <= K; j++)
            {
h[s + 1][i + j][q] = (h[s + 1][i + j][q] + 1ll * h[s][i][q] * h[1][j
            }
        }
        for (int j = 0; i + j <= K; j++)
        {
h[s + 1][i + j][1] = (h[s + 1][i + j][1] + 1ll * h[s][i][0] * h[1][j][1]
        }
    }
}
for (int s = 1, now = m, res = m - 1; s <= k + 1; s++, now = 1ll * now * res % mod,
ans = (ans + 1ll * h[s][K][1] * now % mod * inv[s]) % mod;
}
printf("%d", ans);
}