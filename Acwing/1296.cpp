// Date: 2022-07-20 09:40:29
// Problem: 樱花
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1296/
// Memory Limit: 64 MB
// Time Limit: 1000 ms

// Author: Codeboy

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;
bool st[1000005];
ll primes[1000005], cnt;
ll pfactor[1000005], p[1000005];
ll ans = 1;

void primeseive(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[++cnt] = i;
            pfactor[i] = cnt;
        }
        for (int j = 1; primes[j] * i <= n; j++)
        {
            st[primes[j] * i] = true;
            pfactor[primes[j] * i] = j;
            if (i % primes[j] == 0)
                break;
        }
    }
}

void factorization(int n)
{
    while (n != 1)
    {
        p[pfactor[n]]++;
        n /= primes[pfactor[n]];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    primeseive(n);
    for (int i = 1; i <= n; i++)
    {
        factorization(i);
    }
    for (int i = 1; i <= 100000; i++)
    {
        if (p[i])
            ans = ans * (2 * p[i] + 1) % mod;
    }
    cout << ans << endl;
    return 0;
}
