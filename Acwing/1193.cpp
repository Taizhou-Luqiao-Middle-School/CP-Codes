// Date: 2022-08-03 17:51:08
// Problem: 家谱树
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1193/
// Memory Limit: 64 MB
// Time Limit: 1000 ms

// Author: Codeboy

/////////////////////// Macros & Head ////////////////////

#include <bits/stdc++.h>
#define Re register
#define F(i,l,r) for(int i=l;i<r;++i)
#define Fe(i,l,r) for(int i=l;i<=r;++i)
#define Fer(i,l,r) for(int i=l;i>=r;--i)
#if (__cplusplus < 201703L)
#define rF(i,l,r) for(Re int i=l;i<r;++i)
#define rFe(i,l,r) for(Re int i=l;i<=r;++i)
#define rFer(i,l,r) for(Re int i=l;i>=r;--i)
#endif
#ifndef rF
#define rF(i,l,r) F(i,l,r)
#define rFe(i,l,r) Fe(i,l,r)
#define rFer(i,l,r) Fer(i,l,r)
#endif
using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> PII;
void fastio(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

//////////////////// Global Variables ////////////////////

constexpr int N = 105, M = N * N >> 1;
int e[M], ne[M], h[N], dg[N], idx;
int q[N];
int n;

/////////////////////// Functions ////////////////////////

void add(int a, int b){
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
}

void toposort(){
	int hh = 0, tt = -1;
	rFe(i, 1, n)
		if(!dg[i]) q[++ tt] = i;
	while(hh <= tt){
		int t = q[hh++];
		for(int i = h[t]; ~i; i = ne[i]){
			int v = e[i];
			if(-- dg[v] == 0)
				q[++ tt] = v;
		}
	} 
}

////////////////////// Main Execution ////////////////////

int main(){
  	fastio();
  	cin>>n;
  	memset(h, -1, sizeof h);
  	rFe(i, 1, n){
  		int son;
  		while(cin>>son, son){
  			add(i, son);
  			dg[son] ++;
  		}
  	}
  	
  	toposort();
  	
  	rF(i, 0, n) cout<<q[i]<<' ';
  	cout<<'\n';
  	
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////
