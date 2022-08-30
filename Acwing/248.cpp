// Date: 2022-08-02 18:36:59
// Problem: 一个简单的整数问题
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/248/
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

constexpr int N = 100005;
int a[N], c[N], n;

/////////////////////// Functions ////////////////////////

inline int lowbit(int x){
	return x & -x;
}

void add(int x, int v){
	for(;x<=n;x+=lowbit(x)) c[x]+= v;	
}

void add(int l, int r, int c){
	add(l, c), add(r + 1, -c);
}

ll query(int x){
	ll res = 0;
	for(;x;x-=lowbit(x)) res+=c[x];
	return res;
}

////////////////////// Main Execution ////////////////////

int main(){
  	fastio();
  	int m;
  	cin>>n>>m;
  	Fe(i, 1, n) cin>>a[i];
  	Fe(i, 1, n) add(i, a[i] - a[i - 1]);
  	char op[2]; int l, r, d;
  	Fe(i, 1, m){
  		cin>>op;
  		if(*op == 'C'){
  			cin>>l>>r>>d;
  			add(l, r, d);
  		} else {
  			cin>>l;
  			cout<<query(l)<<endl;
  		}
  	}
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////
