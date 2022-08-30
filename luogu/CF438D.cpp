// Date: 2022-07-31 11:47:11
// Problem: CF438D The Child and Sequence
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF438D
// Memory Limit: 250 MB
// Time Limit: 4000 ms

// Author: Codeboy

/////////////////////// Macros & Head ////////////////////

#include <bits/stdc++.h>
#define int long long
#define F(i, l, r) for (int i = l; i < r; ++i)
#define Fe(i, l, r) for (int i = l; i <= r; ++i)
#define Fer(i, l, r) for (int i = l; i >= r; --i)
using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> PII;
void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

//////////////////// Global Variables ////////////////////

constexpr int N = 100005;
int n, q;
int a[N];

/////////////////////// Functions ////////////////////////

struct SegmentTree
{
    int t[N << 2], maxn[N << 2];
    inline void PushUp(int root)
    {
        t[root] = t[root << 1] + t[root << 1 | 1];
        maxn[root] = max(maxn[root << 1], maxn[root << 1 | 1]);
    }
    void Build(int root, int l, int r)
    {
        if (l == r)
        {
            t[root] = maxn[root] = a[l];
            return;
        }
        int mid = l + r >> 1;
        Build(root << 1, l, mid);
        Build(root << 1 | 1, mid + 1, r);
        PushUp(root);
    }
    void ModifyMod(int root, int l, int r, int tl, int tr, int p)
    {
        if (maxn[root] < p)
            return;
        if (l == r)
        {
            t[root] %= p;
            maxn[root] %= p;
            return;
        }
        int mid = l + r >> 1;
        if (tl <= mid)
            ModifyMod(root << 1, l, mid, tl, tr, p);
        if (tr > mid)
            ModifyMod(root << 1 | 1, mid + 1, r, tl, tr, p);
        PushUp(root);
    }
    void Modify(int root, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            t[root] = maxn[root] = val;
            return;
        }
        int mid = l + r >> 1;
        if (pos <= mid)
            Modify(root << 1, l, mid, pos, val);
        else
            Modify(root << 1 | 1, mid + 1, r, pos, val);
        PushUp(root);
    }
    int Query(int root, int l, int r, int tl, int tr)
    {
        if (tl <= l && r <= tr)
            return t[root];
        int mid = l + r >> 1, res = 0;
        if (tl <= mid)
            res += Query(root << 1, l, mid, tl, tr);
        if (tr > mid)
            res += Query(root << 1 | 1, mid + 1, r, tl, tr);
        return res;
    }
} T;

////////////////////// Main Execution ////////////////////

signed main()
{
    fastio();
    cin >> n >> q;
    Fe(i, 1, n) cin >> a[i];
    T.Build(1, 1, n);
    while (q--)
    {
        int op, x, y, z;
        cin >> op >> x >> y;
        if (op == 1)
            cout << T.Query(1, 1, n, x, y) << endl;
        else if (op == 2)
        {
            cin >> z;
            T.ModifyMod(1, 1, n, x, y, z);
        }
        else
        {
            T.Modify(1, 1, n, x, y);
        }
    }

    return 0;
}

//
////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////////// Farewell! /////////////////////////
