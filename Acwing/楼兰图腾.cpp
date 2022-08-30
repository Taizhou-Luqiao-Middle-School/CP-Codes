#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 200010;

int n, a[N], tr[N], Greater[N], lower[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}

int sum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++)
    {
        int y = a[i];
        Greater[i] = sum(n) - sum(y);
        lower[i] = sum(y - 1);
        add(y, 1);
    }

    memset(tr, 0, sizeof tr);
    long long res1 = 0, res2 = 0;

    for (int i = n; i; i--)
    {
        int y = a[i];
        res1 += Greater[i] * (long long)(sum(n) - sum(y));
        res2 += lower[i] * (long long)(sum(y - 1));
        add(y, 1);
    }
    printf("%lld %lld", res1, res2);

    return 0;
}