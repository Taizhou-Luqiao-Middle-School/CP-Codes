// Date: 2022-08-15 19:11:44
// Problem: P1016 [NOIP1999 提高组] 旅行家的预算
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1016
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
typedef double dou;

//////////////////// Global Variables ////////////////////

constexpr int N = 10;
dou d1, c, d2, d[N], p[N], nx[N];
int n;
bool flag;
double ans = inf;

/////////////////////// Functions ////////////////////////

void dfs(int id, dou rem, dou cost){
	if(id == n + 1){
		chmin(ans, cost);
		flag = true;
		return ;
	}
	cerr<<id<<' '<<rem<<' '<<cost<<endl;

	if(c * d2 < nx[id]) return ;
	dou nxt = 0;
	Fe(i, id ,n){
		nxt += nx[i];
		if(d2 * c < nxt) break;
		dfs(i + 1, c - nxt / d2, cost + p[id] * (c-rem));
		dfs(i + 1, 0, cost + max((dou)0, p[id] * nxt/d2 - p[id] * rem));
	}
}

////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
  	cin>>d1>>c>>d2>>p[0]>>n;
  	// cout<<n<<endl;
  	Fe(i, 1, n){
  		cin>>d[i]>>p[i];
  		nx[i - 1] = d[i] - d[i-1];
  	}
  	cout.precision(2);
  	cout<<fixed;
  	nx[n] = d1 - d[n];
  	dfs(0 , 0, 0);
  	if(flag) {
  		cout<<ans<<endl;
  	} else {
  		cout<<"No Solution"<<endl; 
  	}
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////