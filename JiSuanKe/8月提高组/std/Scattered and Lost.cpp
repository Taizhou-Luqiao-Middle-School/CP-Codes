#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    for (; (c < '0' || c > '9'); c = getchar())
    {
        if (c == '-')
        {
            f = -1;
        }
    }
    for (; (c >= '0' && c <= '9'); c = getchar())
    {
        x = x * 10 + (c & 15);
    }
    return x * f;
}
const int MN = 2e5 + 5;
int n, q, p;
void solve()
{
    n = read(), q = read();
    int mn = 1e9 + 1;
    for (int i = 1; i <= n; i++)
    {
        int x = read();
        if (x < mn)
        {
            mn = x, p = i;
        }
    }
    while (q--)
    {
        int op = read(), l = read(), r = read();
        if (op == 1 && l <= p && p <= r)
        {
            p = l;
        }
        if (op == 2 && l <= p && p <= r)
        {
            p = r;
        }
        if (op == 3 && l <= p && p <= r)
        {
            p = r + l - p;
        }
        if (op == 4)
        {
            int k = read();
            if (k >= r - l + 1)
            {
                if (l <= p && p <= r)
                {
                    p += k;
                }
                else if (l + k <= p && p <= r + k)
                {
                    p -= k;
                }
                continue;
            }
            if (l <= p && p < l + k)
            {
                int t = (int)((r - p + k) / k);
                p += t * k;
            }
            else if (l + k <= p && p <= r + k)
            {
                p -= k;
            }
        }
    }
    cout << p << endl;
}
signed main(void)
{
    freopen("resort.in", "r", stdin);
    freopen("resort.out", "w", stdout);
    int t = read();
    while (t--)
    {
        solve();
    }
    return 0;
}