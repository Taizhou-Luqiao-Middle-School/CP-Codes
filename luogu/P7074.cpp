// Date: 2022-08-15 21:51:52
// Problem: P7074 [CSP-J2020] 方格取数
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P7074
// Memory Limit: 256 MB
// Time Limit: 1000 ms

// Author: Codeboy

/////////////////////// Macros & Head ////////////////////

#include <bits/stdc++.h>
// #define int long long
#define Re register
#define F(i,l,r) for(int i=l;i<r;++i)
#define Fe(i,l,r) for(int i=l;i<=r;++i)
#define Fer(i,l,r) for(int i=l;i>=r;--i)
#define sFe(i,l,r) for(int i=l,_##i=r;i<=_##i;++i)
#define sFer(i,r,l) for(int i=r,_##i=l;i>=_##i;--i)
#define sF(i,l,r) for(int i=l,_##i=r;i<_##i;++i)
#if __cplusplus < 201703L
#define rF(i,l,r) for(Re int i=l;i<r;++i)
#define rFe(i,l,r) for(Re int i=l;i<=r;++i)
#define rFer(i,l,r) for(Re int i=l;i>=r;--i)
#else
#define rF(i,l,r) F(i,l,r)
#define rFe(i,l,r) Fe(i,l,r)
#define rFer(i,l,r) Fer(i,l,r)
#endif
#if __x86_64__ || __ppc64__
typedef __int128 lll;
#else
typedef long long lll;
#endif
#ifndef LOCAL
#define endl '\n'
#endif
#define all(x) (x).begin(),(x).end()
#define enr(i, u) for(int i=h[u];i;i=ne[i])
#define chmax(a, b) if((a)<(b)){(a)=(b);}
#define chmin(a, b) if((a)>(b)){(a)=(b);}
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
clock_t startTime;
inline double getCurrentTime() {return (double)(clock() - startTime) / CLOCKS_PER_SEC;}
inline void fastio(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
constexpr int dir[3][2] = { -1, 0, 1,
							0, 1, 0};
constexpr int inf = 0x3f3f3f3f;
int dx[3] = {-1, 0, 1};
int dy[3] = {0, 1 , 0};

//////////////////// Global Variables ////////////////////

constexpr int N = 1005;
int n, m;
int a[N][N];
int ans = -inf;
ll f[1005][1005][2];

/////////////////////// Functions ////////////////////////

// int dfs(int x, int y){
	// if(x==n && y ==m){
		// return a[x][y];
	// }
	// cerr<<x<<' '<<y<<endl;
	// if(mem[x][y]) return mem[x][y];
	// int aa = -inf;
	// for(int i=0;i<3;++i){
		// int nx = dx[i] + x, ny = dy[i] + y;
		// if(st[nx][ny]) continue;
		// if(nx<1||nx>n||ny<1||ny>m) continue;
		// st[nx][ny] = 1;
		// int tt = dfs(nx, ny) + a[x][y];
		// st[nx][ny] = 0;
		// chmax(aa, tt);
	// }
	// mem[x][y] = aa;
	// return aa;
// }
// 
ll dfs(int x, int y, int prev) {
    if (x < 1 || x > n || y < 1 || y > m) return -inf;
    if (f[x][y][prev] != -inf) return f[x][y][prev];
    if (prev == 0) f[x][y][prev] = max({dfs(x + 1, y, 0), dfs(x, y - 1, 0), dfs(x, y - 1, 1)}) + a[x][y];
    else f[x][y][prev] = max({dfs(x - 1, y, 1), dfs(x, y - 1, 0), dfs(x, y - 1, 1)}) + a[x][y];
    return f[x][y][prev];
}

////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
  	cin>>n>>m;
  	
  	Fe(i ,1 ,n){
  		Fe(j, 1, m){
  			cin>>a[i][j];
  			f[i][j][0] = f[i][j][1] = -inf;
  		}
  	}
  	f[1][1][0] = f[1][1][1] = a[1][1];

  	cout<<dfs(n, m, 1)<<endl;

	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////