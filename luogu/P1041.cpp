// Date: 2022-08-09 09:35:58
// Problem: P1041 [NOIP2003 提高组] 传染病控制
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1041
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
clock_t startTime = clock();
inline double getCurrentTime() {return (double)(clock() - startTime) / CLOCKS_PER_SEC;}
inline void fastio(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
constexpr int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
constexpr int inf = 0x3f3f3f3f;

//////////////////// Global Variables ////////////////////

constexpr int N = 305;
int n, p, sum, h[N], idx = 1; 
int ne[N<<1], e[N<<1];
int dep[N], f[N], cut[N];
vector<int> node[N];
int ans = inf;

/////////////////////// Functions ////////////////////////

inline void add(int a, int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
}

void adde(int a, int b) {
	add(a, b);
	add(b, a);
}

void cuts(int now, int s) {
	cut[now] = s;
	enr(i, now){
		if(e[i] != f[now]) cuts(e[i], s);
	}
}

void dfs1(int nown, int fa) {
    dep[nown]= dep[fa] + 1, f[nown]= fa;
    node[dep[nown]].push_back(nown);
    enr(i, nown){
        if(e[i] != fa) dfs1(e[i], nown);
    }
    return;
}

void dfs2(int deep, int cost) {
    if(cost >= ans) return;
    int notsolve= 0;
    for(int i = 0; i < (int)node[deep].size(); i++)
        if(!cut[node[deep][i]]) ++notsolve;
    if(!notsolve) {
        ans= cost;
        return;
    }
    for(int i = 0; i < (int)node[deep].size(); i++) {
        if(cut[node[deep][i]]) continue;
        cuts(node[deep][i], 1);
        dfs2(deep + 1, cost + notsolve - 1);
        cuts(node[deep][i], 0);
    }
    return;
}

////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
  	int n, p;
  	cin>>n>>p;
  	F(i, 0, p) {
  		int a, b;
  		cin>>a>>b;
  		adde(a, b);
  	}
  	dfs1(1, 0), dfs2(2, 1);
    cout << ans << endl;
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////