#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int mod = 998244353;
int n, f[maxn];
int fac[maxn << 1];
int inv[maxn << 1];
int qmi(int a, int b, int mod)
{
    a %= mod;
    if (!a)
    {
        return 0;
    }
    int result = 1;
    for (; b; a = 1ll * a * a % mod, b >>= 1)
    {
        if (b & 1)
        {
            result = 1ll * result * a % mod;
        }
    }
    return result;
}
int C(const int n, const int m)
{
    if (n < m)
    {
        return 0;
    }
    return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int cal(int a, int b)
{
    return (1ll * C(a + 2 * b, b) - C(a + 2 * b, b - 1) + mod) % mod;
}
void init(const int n)
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = 1ll * fac[i - 1] * i % mod;
    }
    inv[n] = qmi(fac[n], mod - 2, mod);
    for (int i = n - 1; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * (i + 1ll) % mod;
    }
}
int main()
{
    // freopen("stack.in", "r", stdin);
    // freopen("stack.out", "w", stdout);
    scanf("%d", &n);
    init(n << 1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &f[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (f[i])
        {
            ans = (ans + cal(i - 1, n - i)) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}