// Date: 2022-07-19 09:28:48
// Problem: B. Making Towers
// Contest: Codeforces - Codeforces Round #809 (Div. 2)
// URL: https://codeforces.com/contest/1706/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms

// Author: Codeboy

#include <bits/stdc++.h>
using namespace std;
int t, n;
vector<int> a[100100];

int solve(int x)
{
    if (!a[x].size())
        return 0;

    int curr = a[x][0];
    int ans = 1;
    for (int i : a[x])
    {
        if ((i & 1) != (curr & 1))
        {
            ans++;
            curr = i;
        }
    }
    return ans;
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
            a[i].clear();
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            a[x].push_back(i);
        }
        for (int i = 1; i <= n; i++)
        {
            cout << solve(i) << " \n"[i == n];
        }
    }
    return 0;
}
