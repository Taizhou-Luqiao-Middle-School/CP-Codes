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
constexpr int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
constexpr int inf = 0x3f3f3f3f;

//////////////////// Global Variables ////////////////////

constexpr int N = 2005, mod = 998244353;
vector<int> g[N];
ll ans;
int a[N];
int s[N];

/////////////////////// Functions ////////////////////////

// int dfs(int rt, int lf){
	// if(g[rt].empty()){
		// if(lf>=1) return 2;
		// return 1;
	// }
	// ll res = 0;
	// for(auto i:g[rt]){
		// res = res + dfs(i, min(a[i], lf)) % mod;
		// res = res + dfs(i, min(lf - 1, a[i])) % mod;
	// }
	// return res;
// }


int dfs(int rt){
	if(g[rt].empty()){
		s[rt] = 1;
		return 1;
	}
	
	for(auto i:g[rt]){
		s[rt] += dfs(i);
	}
	s[rt] ++ ;
	return s[rt];
}

////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
	#ifndef LOCAL
  	freopen("appletree.in", "r", stdin);
  	freopen("appletree.out", "w", stdout);
  	#endif
  	int n;
  	cin>>n;
  	Fe(i, 1, n) cin>>a[i];
  	Fe(i, 1, n-1){
  		int x, y;
  		cin>>x>>y;
  		g[x].pb(y);
  	}

	int siz = dfs(1);
	cout<<siz<<endl;
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////