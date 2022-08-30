#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
const int NMAX = 2100;
const int MOD = 998244353;
vector<int> E[NMAX];
int limit[NMAX], siz[NMAX];
int dp[NMAX][NMAX];
void solve(int x, int fa)
{
    siz[x] = 1;
    dp[x][0] = 1;
    if (limit[x] >= 1)
    {
        dp[x][1] = 1;
    }
    for (auto y : E[x])
    {
        if (y == fa)
        {
            continue;
        }
        solve(y, x);
        for (int i = siz[x] + siz[y]; i >= 0; i -= 1)
        {
            if (i > limit[x])
            {
                dp[x][i] = 0;
                continue;
            }
            int j_init = max(i - siz[x], 1);
            int j_lim = min(siz[y], i);
            for (int j = j_init; j <= j_lim; j += 1)
            {
                (dp[x][i] += (long long)dp[y][j] * dp[x][i - j] % MOD) %= MOD;
            }
        }
        siz[x] += siz[y];
    }
}
int main()
{
    freopen("appletree.in", "r", stdin);
    freopen("appletree.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i += 1)
    {
        scanf("%d", &limit[i]);
    }
    for (int i = 1; i < n; i += 1)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        E[x].push_back(y);
        E[y].push_back(x);
    }
    solve(1, -1);
    int ans = 0;
    for (int i = 0; i <= limit[1] && i <= n; i += 1)
    {
        (ans += dp[1][i]) %= MOD;
    }
    printf("%d\n", ans);
    exit(0);
}