// Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Re register
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))
using namespace std;
typedef long long ll;
const int N = 50010;

int primes[N], cnt;
bool st[N];
int mobius[N], sum[N];

void init(int n)
{
    mobius[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i;
            mobius[i] = -1;
        }
        for (int j = 0; primes[j] * i <= n; j++)
        {
            int t = primes[j] * i;
            st[t] = true;
            if (i % primes[j] == 0)
            {
                mobius[t] = 0;
                break;
            }
            mobius[t] = mobius[i] * -1;
        }
    }

    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + mobius[i];
}

int main()
{
    init(N - 1);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b, d;
        scanf("%d%d%d", &a, &b, &d);
        a /= d, b /= d;
        int n = min(a, b);
        ll res = 0;
        for (int l = 1, r; l <= n; l = r + 1)
        {
            r = min(n, min(a / (a / l), b / (b / l)));
            res += (sum[r] - sum[l - 1]) * (ll)(a / l) * (b / l);
        }
        printf("%lld\n", res);
    }

    return 0;
}