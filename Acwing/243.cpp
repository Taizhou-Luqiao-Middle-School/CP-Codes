// Date: 2022-08-02 17:50:24
// Problem: 楼兰图腾
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/243/
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

constexpr int N = 200005;
int tr[N], a[N], n;
int g[N], l[N];

/////////////////////// Functions ////////////////////////

inline int lowbit(int x){return x&(-x);}

void add(int x){
	for(;x<=n;x+=lowbit(x)){
		++ tr[x];
	}
}

ll query(int x){
	ll res = 0;
	for(;x;x-=lowbit(x)){
		res += tr[x];
	}
	return res;
}


////////////////////// Main Execution ////////////////////

int main(){
  	fastio();
  	cin>>n;
  	rFe(i, 1, n) cin>>a[i];
  	rFe(i, 1, n){
  		int y = a[i];
  		g[i] = query(n) - query(y);
  		l[i] = query(y - 1);
  		add(y);
  	}
  	memset(tr, 0, sizeof tr);
  	ll res1 = 0, res2 = 0;
  	rFer(i, n, 1){
  		int y = a[i];
  		res1 += g[i] * (query(n) - query(y));
  		res2 += l[i] * query(y - 1);
  		add(y);
  	}
  	cout<<res1<<' '<<res2<<endl;
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////////// So long, Farewell! /////////////////////////
