// Date: 2022-08-12 15:59:35
// Problem: P1950 长方形
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1950
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

constexpr int N = 1005;
int n, m;
char a[N][N];
int h[N][N], st[N], l[N], r[N];
int top = 0;
ll ans;

/////////////////////// Functions ////////////////////////

// Monotonic stack operator
inline void work(int x) {
	top = 0;
	rFe(i, 1, m){
		while(top && h[x][st[top]] >= h[x][i]) {
			r[st[top--]] = i;
		}
		st[++top] = i;
	}
	while(top) r[st[top--]] = m + 1;
	rFer(i, m, 1){
		while(top && h[x][st[top]] > h[x][i]) {
			l[st[top--]] = i;
		}
		st[++top] = i;
	}
	while(top) l[st[top--]] = 0;
}

ll solve(){
	ll res = 0;
	rFe(i, 1, n){
  		work(i);
  		rFe(j, 1, m){
  			res += (j - l[j]) * (r[j] - j) * h[i][j];
  		}
  	}
  	return res;
}

////////////////////// Main Execution ////////////////////

signed main(){
  	cin>>n>>m;
  	rFe(i, 1, n) scanf("%s", a[i] + 1);
  	rFe(i, 1, n){
  		rFe(j, 1, m){
  			if(a[i][j] == '*') h[i][j] = 0;
  			else h[i][j] = h[i-1][j] + 1;
  		}
  	}
  	cout<<solve()<<endl;
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////