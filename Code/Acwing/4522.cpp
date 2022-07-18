// Date: 2022-07-18 17:28:06
// Problem: 正方形数组的数目
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/4522/
// Memory Limit: 64 MB
// Time Limit: 1000 ms

// Author: Codeboy

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res;
int n, a[20];
int st[20];

bool check(int num)
{
    int p = (int)sqrt(num);
    return p * p == num;
}

void dfs(int u, int last)
{
    if (u >= n)
    {
        res++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (st[i] || (i > 0 && !st[i - 1] && a[i] == a[i - 1]))
            continue;
        if (check(last + a[i]))
        {
            st[i] = true;
            dfs(u + 1, a[i]);
            st[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || a[i] != a[i - 1])
        {
            st[i] = true;
            dfs(1, a[i]);
            st[i] = false;
        }
    }

    cout << res << endl;
    return 0;
}
