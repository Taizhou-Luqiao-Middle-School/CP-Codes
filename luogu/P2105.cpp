// Date: 2022-08-11 21:12:27
// Problem: P2105 K皇后
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2105
// Memory Limit: 31 MB
// Time Limit: 1000 ms

// Author: Codeboy

/////////////////////// Macros & Head ////////////////////

#include <bits/stdc++.h>
// #define int long long
#define Re register
#define F(i,l,r) for(int i=l;i<r;++i)
#define Fe(i,l,r) for(int i=l;i<=r;++i)
#define Fer(i,l,r) for(int i=l;i>=r;--i)
#if __cplusplus < 201703L
#define rF(i,l,r) for(Re int i=l;i<r;++i)
#define rFe(i,l,r) for(Re int i=l;i<=r;++i)
#define rFer(i,l,r) for(Re int i=l;i>=r;--i)
#endif
#ifndef rF
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
constexpr int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
constexpr int inf = 0x3f3f3f3f;

//////////////////// Global Variables ////////////////////

constexpr int N = 2010000, ofse = 22000;
int row[N], col[N], dia1[N<<1], dia2[N<<1];
int x,y,n,m,k;

/////////////////////// Functions ////////////////////////



////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
  	int n, m, k;
  	cin>>n>>m>>k;
  	Fe(i, 1, k){
  		int x, y;
  		cin>>x>>y;
  		row[x] = 1;
  		col[y] = 1;
  		dia1[x+y] = 1;
  		dia2[x-y+ofse] = 1;
  	}
  	int ans = 0;
  	Fe(i, 1, n){
  		if(row[i]) continue;
  		Fe(j, 1, m){
  			if(col[j] || dia1[i + j] || dia2[i - j + ofse]) continue;
  			else ++ ans;
  		}
  	}
  	
  	cout<<ans<<endl;
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////