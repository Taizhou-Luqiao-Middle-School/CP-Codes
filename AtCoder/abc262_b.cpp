// Date: 2022-08-01 19:09:41
// Problem: B - Triangle (Easier)
// Contest: AtCoder - AtCoder Beginner Contest 262
// URL: https://atcoder.jp/contests/abc262/tasks/abc262_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

// Author: Codeboy

/////////////////////// Macros & Head ////////////////////

#include <bits/stdc++.h>
#define Re register
#define F(i,l,r) for(int i=l;i<r;++i)
#define Fe(i,l,r) for(int i=l;i<=r;++i)
#define Fer(i,l,r) for(int i=l;i>=r;--i)
using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> PII;
void fastio(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

//////////////////// Global Variables ////////////////////

constexpr int N = 105;
int g[N][N];
int ans;

/////////////////////// Functions ////////////////////////



////////////////////// Main Execution ////////////////////

int main() {
	fastio();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u -= 1, v -= 1;
        g[u][v] = g[v][u] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (g[i][j] && g[j][k] && g[k][i]) {
                    ans += 1;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////////// Farewell! /////////////////////////