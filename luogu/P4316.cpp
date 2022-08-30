// Date: 2022-08-15 14:30:52
// Problem: P4316 绿豆蛙的归宿
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4316
// Memory Limit: 125 MB
// Time Limit: 1000 ms

// Author: Codeboy

/////////////////////// Macros & Head ////////////////////

#include <bits/stdc++.h>
// #define int long long
#define Re register
#define F(i,l,r) for(int i=l;i<r;++i)
#define Fe(i,l,r) for(int i=l;i<=r;++i)
#define Fer(i,l,r) for(int i=l;i>=r;--i)
#define sFe(i,l,r) for(int i=l, _##i=r;i<=_##i;++i)
#define sFer(i,r,l) for(int i=r,_##i=l;i>=_##i;--i)
#define sF(i,l,r) for(int i=l,__i=r;i<__i;++i)
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

constexpr int N = 100005;
int h[N], e[N<<1], ne[N<<1], w[N<<1], idx;
int n, m;
int dg[N];
double f[N];

/////////////////////// Functions ////////////////////////

void add(int a, int b, int c){
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx ++;
}

double dp(int u){
	if(f[u]>0) return f[u];
	f[u] = 0;
	for (int i = h[u]; ~i; i = ne[i]){
		int j = e[i];
		f[u] += (w[i] + dp(j)) / dg[u];
	}
	
	return f[u];
}

////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
  	cin>>n>>m;
    memset(h, -1, sizeof h);

  	F(i, 0, m){
  		int a, b, c;
  		cin>>a>>b>>c;
  		add(a, b, c);
  		dg[a] ++;	
  	}
  	memset(f, -1, sizeof f);
  	cout.precision(2);
  	cout<<fixed<<dp(1)<<endl;
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////