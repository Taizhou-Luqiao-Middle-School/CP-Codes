// Date: 2022-07-19 10:46:54
// Problem: C. Qpwoeirut And The City
// Contest: Codeforces - Codeforces Round #809 (Div. 2)
// URL: https://codeforces.com/contest/1706/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms

// Author: Codeboy

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;
int a[100005];

ll calc(int i)
{
    return max(max(a[i - 1], a[i + 1]) - a[i] + 1, 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        if (n & 1)
        {
            ll ans = 0;
            for (int i = 2; i < n; i += 2)
            {
                ans += calc(i);
            }

            cout << ans << endl;
            continue;
        }
        ll tmp = 0;
        for (int i = 2; i < n; i += 2)
        {
            tmp += calc(i);
        }
        ll ans = tmp;
        for (int i = n - 1; i > 1; i -= 2)
        {
            tmp -= calc(i - 1);
            tmp += calc(i);
            ans = min(ans, tmp);
        }
        cout << ans << endl;
    }
    return 0;
}
