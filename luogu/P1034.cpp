// Date: 2022-08-11 10:38:16
// Problem: P1034 [NOIP2002 提高组] 矩形覆盖
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1034
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

constexpr int N = 60;
int n, k, x[N], y[N], ans = inf;
struct mat {
	int lx, ly, rx, ry;
	bool cnt;
	void add(int x, int y) {
		if(!cnt) {
			lx = rx = x;
			ly = ry = y;
			cnt = 1;
		} else {
			if(x < lx) lx = x;
			else if(x > rx) rx = x;
			if(y > ly) ly = y;
			else if(y < ry) ry = y;
		}
	}
	bool in(int x, int y) const {
		return lx <= x && x <= rx && ry <= y && y <= ly;
	}
	int operator() () {
		if(!cnt) return 0;
		return (rx - lx) * (ly - ry);
	}
	bool operator* (const mat &o) {
		if(!cnt || !o.cnt) return 0;
		return o.in(lx, ly) || o.in(lx, ry) ||
			o.in(rx, ly) || o.in(rx, ry);
	}
} mats[5];

/////////////////////// Functions ////////////////////////

bool check() {
	Fe(i, 1, k)
		Fe(j, i + 1, k)
			if(mats[i] * mats[j]) return 0;
	return 1;
}

void dfs(int i, int area) {
	if(area >= ans) return;
	if(i == n) {
		if(check())
			if(ans > area) ans = area;
		return;
	}
	mat tmp;
	Fe(j, 1, k) {
		tmp = mats[j];
		mats[j].add(x[i], y[i]);
		dfs(i + 1, area - tmp() + mats[j]());
		mats[j] = tmp;
	}
}

////////////////////// Main Execution ////////////////////

signed main(){
	fastio();
	cin>>n>>k;
	for(int i = 0;i < n;i++)
		cin>>x[i]>>y[i];
	dfs(0, 0);
	cout<<ans<<endl;
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////