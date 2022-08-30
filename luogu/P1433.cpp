// Date: 2022-08-08 20:41:51
// Problem: P1433 吃奶酪
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1433
// Memory Limit: 128 MB
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

constexpr int N = 30;
double dist[N][N], x[N], y[N], f[N][1<<16], ans;


/////////////////////// Functions ////////////////////////

inline double dis(int a, int b){
	return sqrt((x[a] - x[b])*(x[a] - x[b]) +  (y[a] - y[b])*(y[a] - y[b]));
}

////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
  	memset(f, 127, sizeof f);
  	ans = f[0][0];
  	int n;
  	cin>>n;
  	Fe(i, 1, n) cin>>x[i]>>y[i];
  	x[0] = y[0] = 0;
  	Fe(i, 0, n){
  		Fe(j, i + 1, n){
  			dist[i][j] = dist[j][i] = dis(i, j);
  		}
  	}
  	Fe(i, 1, n){
  		f[i][1<<(i-1)] = dist[0][i];
  	}
  	Fe(i, 1, n) Fe(j, 1, n) cout<<dist[i][j]<<"\n "[j!=n];
  	F(k, 1, 1<<n){
  		Fe(i, 1, n){
  			if((k & (1<<(i-1)))==0) continue;
  			Fe(j, 1, n){
  				if(i == j) continue;
  				if((k & (1<<(j-1)))==0) continue;
  				f[i][k] = min(f[i][k], f[j][k-(1<<(i-1))] + dist[i][j]);
  			}
  		}
  	}
  	
  	Fe(i, 1, n){
  		ans = min(ans, f[i][(1<<n)-1]);
  		cout<<ans<<endl;
  	}
  	cout.precision(2);
  	cout<<fixed<<ans<<endl;
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////