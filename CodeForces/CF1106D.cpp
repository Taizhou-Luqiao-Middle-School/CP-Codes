// Date: 2022-08-08 17:01:51
// Problem: CF1106D Lunar New Year and a Wander
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1106D
// Memory Limit: 250 MB
// Time Limit: 3000 ms

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
#define enr(i, u) for(int i=h[u];i;i=ne[i])
#define all(x) (x).begin(),(x).end()
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

constexpr int N = 200005;
int h[N], e[N], ne[N], idx = 1, cnt;
int ans[N];
// vector<bool> vis(N);
bool vis[N];
priority_queue<int, vector<int>, greater<int>> q;

/////////////////////// Functions ////////////////////////

inline void add(int u, int v){
	// enr(i, u) if(e[i] == v) return; // Detects the presence of duplicate edges
	e[idx] = v;
	ne[idx] = h[u];
	h[u] = idx ++;  
}

void adde(int u, int v){
	add(u, v);
	add(v, u);
}
 
////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
  	int m, n;
  	cin>>n>>m;
  	F(i, 0, m){
  		int u, v;
  		cin>>u>>v;
  		adde(u, v);
  	}
  	
  	
  	q.push(1);
  	
  	while(!q.empty()){
  		int t = q.top(); q.pop();
		vis[t]=1;
  		ans[cnt++] = t;
  		enr(i, t){
  			int v = e[i];
  			if(!vis[v]) {
  				vis[v] = 1;
  				q.push(v);
  			}
  		}
  	}
    
  	F(i, 0, n) cout<<ans[i]<<' ';
  	cout<<'\n';
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////
