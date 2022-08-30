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
ll res = 0;
int main()
{
    ll n, k;
    cin >> n >> k;
    res = n * k;
    for (int l = 1, r; l <= n && k / l >= 1; l = r + 1)
    {
        r = min(n, k / (k / l));
        res -= (k / l) * (l + r) * (r - l + 1) / 2;
    }

    cout << res << endl;
    return 0;
}