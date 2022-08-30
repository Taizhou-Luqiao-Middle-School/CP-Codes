// Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int mod = 9901;

int qpow(int a, int k)
{
    int res = 1;
    a %= mod;
    while (k)
    {
        if (k & 1)
            res = res * a % mod;
        a = a * a % mod;
        k >>= 1;
    }
    return res;
}
int sum(int p, int k) //k代表项数
{
    if (k == 1)
        return 1;
    if (k % 2 == 0)
    {
        return (1 + qpow(p, k / 2)) * sum(p, k / 2) % mod;
    }
    else
    {
        return (sum(p, k - 1) + qpow(p, k - 1)) % mod;
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    int res = 1;
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            int s = 0;
            while (a % i == 0)
            {
                a /= i, s++;
            }
            res = res * sum(i, b * s + 1) % mod;
        }
    }
        if (a > 1)
            res = res * sum(a, b + 1) % mod;
        if (a == 0)
            res = 0;
    
    cout << res << endl;
    return 0;
}