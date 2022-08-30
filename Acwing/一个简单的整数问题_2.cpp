#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 100010;

int n, m;
ll tr1[N], tr2[N];
int a[N];
int lowbit(int x)
{
    return x & -x;
}
void add(ll tr[], int x, ll c)
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        tr[i] += c;
    }
}
ll sum(ll tr[], int x)
{
    ll res = 0;
    for (int i = x; i; i -= lowbit(i))
    {
        res += tr[i];
    }
    return res;
}
ll prefix_sum(int x)
{
    return sum(tr1, x) * (x + 1) - sum(tr2, x);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        int b = a[i] - a[i - 1];
        add(tr1, i, b);
        add(tr2, i, (ll)b * i);
    }
    while (m--)
    {
        char op[2];
        int l, r, d;
        scanf("%s%d%d", op, &l, &r);
        if (*op == 'Q')
        {
            printf("%lld\n", prefix_sum(r) - prefix_sum(l - 1));
        }
        else
        {
            scanf("%d", &d);
            add(tr1, l, d), add(tr2, l, l * d);
            add(tr1, r + 1, -d), add(tr2, r + 1, (r + 1) * -d);
        }
    }
    return 0;
}