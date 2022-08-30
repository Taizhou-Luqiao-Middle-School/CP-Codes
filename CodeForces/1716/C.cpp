// Date: 2022-08-06 10:13:54
// Problem: C. Robot in a Hallway
// Contest: Codeforces - Educational Codeforces Round 133 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1716/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms

// Author: Codeboy

/////////////////////// Macros & Head ////////////////////

#include <bits/stdc++.h>
// #define int long long
#define Re register
#define F(i, l, r) for (int i = l; i < r; ++i)
#define Fe(i, l, r) for (int i = l; i <= r; ++i)
#define Fer(i, l, r) for (int i = l; i >= r; --i)
#if (__cplusplus < 201703L)
#define rF(i, l, r) for (Re int i = l; i < r; ++i)
#define rFe(i, l, r) for (Re int i = l; i <= r; ++i)
#define rFer(i, l, r) for (Re int i = l; i >= r; --i)
#endif
#ifndef rF
#define rF(i, l, r) F(i, l, r)
#define rFe(i, l, r) Fe(i, l, r)
#define rFer(i, l, r) Fer(i, l, r)
#endif
using namespace std;
typedef long long ll;
#if __x86_64__ || __ppc64__
typedef __int128 lll;
#else
typedef ll lll;
#endif
typedef pair<int, int> PII;
inline void fastio()
{ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
constexpr int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
constexpr int inf = 0x3f3f3f3f;

//////////////////// Global Variables ////////////////////

constexpr int N = 200005;
int a[3][N], f[3][N];
int m;

/////////////////////// Functions ////////////////////////

////////////////////// Main Execution ////////////////////

signed main()
{
    fastio();
    int t;
    cin >> t;
    while (t--)
    {
        cin >> m;
        Fe(i, 1, 2) Fe(j, 1, m) 
        	cin >> a[i][j];

        f[1][m + 1] = f[2][m + 1] = 0;
        
        Fe(i, 1, 2) Fer(j, m, 1) 
			f[i][j] = max({
				f[i][j + 1] - 1, 
				a[i][j], 
				a[3 - i][j] - ((m - j + 1) * 2 - 1)
			});

        int mx = a[2][1], res = max(mx, f[2][2] - 1);
        
        res = min(res, max(f[1][2], a[2][1] - (m - 1) * 2));
        
		Fe(i, 2, m) {
            if (i & 1) {
                mx = max({
                	mx, 
                	a[1][i] - ((i - 1) * 2 - 1), 
                	a[2][i] - (i - 1) * 2
                });
                
                res = min(res, max(mx, f[2][i + 1] - (i * 2 - 1)));
            } else {
                mx = max({
                	mx, 
                	a[2][i] - ((i - 1) * 2 - 1), 
                	a[1][i] - (i - 1) * 2
                });
                
                res = min(
                		res, 
                	max(mx, 
                	f[1][i + 1] - (i * 2 - 1)
                ));
            }
        }

        cout << (2 * m - 1) + max(0, res) << '\n';
    }
    return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////