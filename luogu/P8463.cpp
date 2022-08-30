// Date: 2022-08-14 16:49:31
// Problem: P8463 「REOI-1」深潜的第六兽
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P8463
// Memodry Limit: 128 MB
// Time Limit: 1000 ms

// Author: Codeboy

/////////////////////// Macros & Head ////////////////////

#include <bits/stdc++.h>
// #define int long long
#define Re register
#define F(i, l, r) for (int i = l; i < r; ++i)
#define Fe(i, l, r) for (int i = l; i <= r; ++i)
#define Fer(i, l, r) for (int i = l; i >= r; --i)
#if __cplusplus < 201703L
#define rF(i, l, r) for (Re int i = l; i < r; ++i)
#define rFe(i, l, r) for (Re int i = l; i <= r; ++i)
#define rFer(i, l, r) for (Re int i = l; i >= r; --i)
#else
#define rF(i, l, r) F(i, l, r)
#define rFe(i, l, r) Fe(i, l, r)
#define rFer(i, l, r) Fer(i, l, r)
#endif
#if __x86_64__ || __ppc64__
typedef __int128 lll;
#else
typedef long long lll;
#endif
#ifndef LOCAL
#define endl '\n'
#endif
#define all(x) (x).begin(), (x).end()
#define enr(i, u) for (int i = h[u]; i; i = ne[i])
#define chmax(a, b)                                                                                                    \
    if ((a) < (b))                                                                                                     \
    {                                                                                                                  \
        (a) = (b);                                                                                                     \
    }
#define chmin(a, b)                                                                                                    \
    if ((a) > (b))                                                                                                     \
    {                                                                                                                  \
        (a) = (b);                                                                                                     \
    }
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
clock_t startTime;
inline double getCurrentTime()
{
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
inline void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
constexpr int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 500010;
#define ls(x) x << 1
#define rs(x) x << 1 | 1
const int maxn = 100000;
const int mod = 998244353;

//////////////////// Global Variables ////////////////////


int n, m, ans, x, f[N], d[N << 2], tag[N << 2];
struct node
{
    int l, r, h;
    bool operator<(const node &A) const
    {
        return h == A.h ? l < A.l : h < A.h;
    }
} a[N];

/////////////////////// Functions ////////////////////////

void pushdown(int x)
{
    if (tag[x])
    {
        d[ls(x)] = tag[x];
        d[rs(x)] = tag[x];
        tag[ls(x)] = tag[x];
        tag[rs(x)] = tag[x];
        tag[x] = 0;
    }
}

void modify(int k, int l, int r, int x, int y, int p)
{
    if (x <= l && r <= y)
    {
        d[k] = p;
        tag[k] = p;
        return;
    }

    int mid = l + r >> 1;
    pushdown(k);
    if (x <= mid)
        modify(ls(k), l, mid, x, y, p);
    if (y > mid)
        modify(rs(k), mid + 1, r, x, y, p);
}

int query(int k, int l, int r, int x)
{
    if (l == r)
        return d[k];
    int mid = l + r >> 1, ret = 0;
    pushdown(k);
    if (x <= mid)
        ret = query(ls(k), l, mid, x);
    else
        ret = query(rs(k), mid + 1, r, x);
    return ret;
}

////////////////////// Main Execution ////////////////////

signed main()
{
    fastio();
    cin >> n >> m;
    Fe(i, 1, m)
    {
        cin >> a[i].l >> a[i].r >> a[i].h;
    }
    sort(a + 1, a + m + 1);
    Fe(i, 1, m)
    {
        int L = a[i].l, R = a[i].r;
        int ql = query(1, 0, maxn, L), qr = query(1, 0, maxn, R);
        if (ql == 0 && qr == 0)
            f[i] = 2;
        else if (ql == 0 || qr == 0)
            f[i] = (f[ql] + f[qr] + 1) % mod;
        else
            f[i] = (f[ql] + f[qr]) % mod;
        modify(1, 0, maxn, L, R, i);
    }
	int tmp;
    Fe(i, 1, n)
    {
        cin >> x;
        tmp = f[query(1, 0, maxn, x)];
        if (!tmp)
            ans++;
        else
            ans += tmp;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////