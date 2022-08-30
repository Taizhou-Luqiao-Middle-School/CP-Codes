// Date: 2022-07-17 20:00:25
// Problem: B - Better Students Are Needed!
// Contest: AtCoder - AtCoder Beginner Contest 260
// URL: https://atcoder.jp/contests/abc260/tasks/abc260_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

// Author: Codeboy

#include <bits/stdc++.h>
using namespace std;
int st[1005], a[1005], b[1005], c[1005];
int mm[1005], cnt;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        c[i] = b[i] + a[i];
    }
    for (int j = 0; j < x; j++)
    {
        int t = -1, id = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] >= t && !st[i])
            {
                id = i;
                t = a[i];
            }
        }
        st[id] = 1;
        mm[cnt++] = id;
    }
    for (int j = 0; j < y; j++)
    {
        int t = -1, id = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (b[i] >= t && !st[i])
            {
                id = i;
                t = b[i];
            }
        }
        st[id] = 1;
        mm[cnt++] = id;
    }
    for (int j = 0; j < z; j++)
    {
        int t = -1, id = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (c[i] >= t && !st[i])
            {
                id = i;
                t = c[i];
            }
        }
        st[id] = 1;
        mm[cnt++] = id;
    }
    sort(mm, mm + cnt);
    for (int i = 0; i < cnt; i++)
    {
        cout << mm[i] + 1 << endl;
    }
    return 0;
}
