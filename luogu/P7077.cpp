// Date: 2022-08-19 19:34:08
// Problem: P7077 [CSP-S2020] 函数调用
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P7077
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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

constexpr int N = 1000005, mod = 998244353;
int h[N], e[N << 1], ne[N << 1], idx = 1, dg[N];
ll a[N];
int n, m, Q, F[N];

/////////////////////// Functions ////////////////////////

struct OPERATOR {
	int tp, p;
	ll v, mul, sum; 
} op[N];

inline void adde(int a, int b){
	e[idx] = b;
	dg[b] ++;
	ne[idx] = h[a];
	h[a] = idx++; 
}

// inline void adde(int u, int v) {
	// ne[++idx] = h[u]; h[u] = idx; e[idx] = v; dg[v]++;
// }

queue<int> q;
int que[N], idq;
void toposort(){
	Fe(i, 1, m) if(!dg[i]) q.push(i);
	while(!q.empty()){
		int t = q.front(); q.pop();
		que[++idq] = t;
		enr(i, t){
			int b = e[i];
			dg[b] --;
			if(!dg[b]) q.push(b);
		}
	}
}

void calcm(){
	Fer(i, m, 1){
		int t = que[i];
		enr(j, t){
			int b = e[j];
			op[t].mul = op[t].mul * op[b].mul % mod;
		}
	}
}

void calcs(){
	Fe(i, 1, m){
		int t = que[i];
		ll now = 1;
		enr(j, t){
			int b = e[j];
			op[b].sum = (op[b].sum + op[t].sum * now % mod) % mod;
			now = now * op[b].mul % mod;
		}
	}
}

////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
  	cin>>n;
  	Fe(i, 1, n) cin>>a[i];
  	cin>>m;
  	Fe(i, 1, m){
  		cin>>op[i].tp;
  		if(op[i].tp == 1){
  			cin>>op[i].p>>op[i].v;
  			op[i].mul = 1;
  		} else if(op[i].tp == 2){
  			cin>>op[i].v;
  			op[i].mul = op[i].v;
  		} else {
  			cin>>op[i].p;
  			op[i].mul = 1;
  			int x;
  			Fe(j, 1, op[i].p){
  				cin>>x;
  				adde(i, x);
  			}
  		}
  	}
  	toposort();
  	calcm();
  	cin>>Q;
  	ll now = 1;
  	Fe(i, 1, Q) cin>>F[i];
  	Fer(i, Q, 1){
  		int x = F[i];
  		op[x].sum = (op[x].sum + now) % mod;
  		now = now * op[x].mul % mod;
  	}
  	calcs();
  	Fe(i, 1, n) a[i] = a[i] * now % mod;
  	Fe(i ,1, m){
  		if(op[i].tp==1){
  			a[op[i].p] = (a[op[i].p] + op[i].v * op[i].sum % mod) % mod;
  		}
  	}
  	Fe(i, 1, n) {
  		cout<<a[i]<<' ';
  	}
  	
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////