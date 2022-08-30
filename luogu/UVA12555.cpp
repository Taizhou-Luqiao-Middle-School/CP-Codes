// Date: 2022-08-08 21:24:45
// Problem: UVA12555 Baby Me
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA12555#submit
// Memory Limit: 0 MB
// Time Limit: 1000 ms

// Author: Codeboy

/////////////////////// Macros & Head ////////////////////

#include <bits/stdc++.h>
// #define int long long
#define gister
#define F(i, l, r) for (int i = l; i < r; ++i)
#define Fe(i, l, r) for (int i = l; i <= r; ++i)
#define Fer(i, l, r) for (int i = l; i >= r; --i)
#if __cplusplus < 201703L
#define rF(i, l, r) for (int i = l; i < r; ++i)
#define rFe(i, l, r) for (int i = l; i <= r; ++i)
#define rFer(i, l, r) for (int i = l; i >= r; --i)
#endif
#ifndef rF
#define rF(i, l, r) F(i, l, r)
#define rFe(i, l, r) Fe(i, l, r)
#define rFer(i, l, r) Fer(i, l, r)
#endif
#if __x86_64__ || __ppc64__
typedef __int128 lll;
#else
typedef long long lll;
#endif
#define all(x) (x).begin(), (x).end()
#define enr(i, u) for (int i = h[u]; i; i = ne[i])
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
clock_t startTime;
inline double getCurntTime()
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

//////////////////// Global Variables ////////////////////

constexpr int N = 105;
int t, a, b;
string s;

/////////////////////// Functions ////////////////////////

////////////////////// Main Execution ////////////////////

signed main()
{
    scanf("%d ", &t);
    for (int i = 1; i <= t; ++i)
    {
        getline(cin, s);
        printf("Case %d: ", i);
        bool pd = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] <= '9' && s[i] >= '0')
                if (pd)
                    b = b * 10 + s[i] - '0';
                else
                    a = a * 10 + s[i] - '0';
            else
                pd = 1;
        }
        double ans = a * 0.5 + b * 0.05;
        int x = ans * 100;
        if (!(x % 100))
            printf("%.0lf\n", ans);
        else if (!(x % 10))
            printf("%.1lf\n", ans);
        else
            printf("%.2lf\n", ans);
		s = "";
        a = 0, b = 0;
    }
    return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Fawell! ////////////////////