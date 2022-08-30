// Date: 2022-07-18 19:54:30
// Problem: 最大连续子序列
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/3655/
// Memory Limit: 64 MB
// Time Limit: 1000 ms

// Author: Codeboy

#include <bits/stdc++.h>
using namespace std;
int t, s, d, ma ,mi, f, l ,r, ll, k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> k)
    {
        s = t = 0;
        ma = -1, mi = 0;
        f = l = r = ll = 0;
        for (int i = 0; i < k; i++)
        {
            cin >> t;
			if(!f) ma = t, f = 1; 
            s += t;
            d = s - mi;
            if (d > ma) ma = d, r = i, l = ll;
            if (s < mi) mi = s, ll = i + 1;
        }
        cout << max(ma, 0) << ' ' << l << ' ' << r << endl;
    }
    return 0;
}
