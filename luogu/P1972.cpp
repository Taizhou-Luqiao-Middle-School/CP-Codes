// Date: 2022-07-31 20:03:47
// Problem: P1972 [SDOI2009] HH的项链
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1972
// Memory Limit: 512 MB
// Time Limit: 2000 ms

// Author: Codeboy

/////////////////////// Macros & Head ////////////////////

#include <bits/stdc++.h>
#define Re register
#define F(i,l,r) for(int i=l;i<r;++i)
#define Fe(i,l,r) for(int i=l;i<=r;++i)
#define Fer(i,l,r) for(int i=l;i>=r;--i)
using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> PII;
void fastio(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

//////////////////// Global Variables ////////////////////

constexpr int N = 1000010;
int n,m;
int a[N],ans[N];
int vis[N],tree[N];

struct QUE{
	int l;
	int r;
	int id;
}q[N];

/////////////////////// Functions ////////////////////////

inline bool cmp(const QUE &a, const QUE &b){
	return a.r < b.r;
}

inline int lowbit(int x){
	return x&(-x);
}

void modify(int p,int v){
	for(;p<=n;p+=lowbit(p))
		tree[p]+=v;
}

int query(int p){
	int res=0;
	for(;p;p-=lowbit(p))
		res+=tree[p];
	return res;
}

////////////////////// Main Execution ////////////////////

int main(){
	fastio();
	cin>>n;
	Fe(i, 1, n) cin>>a[i];
	cin>>m;
	Fe(i, 1, m){
		cin>>q[i].l>>q[i].r;
		q[i].id = i;
	}
	
	sort(q+1, q+m+1, cmp);
	
	int pow = 1;
	Fe(i, 1, m){
		Fe(j, pow, q[i].r){
			if(vis[a[j]]) modify(vis[a[j]], -1);
			modify(j, 1);
			vis[a[j]] = j;
		}
		pow=q[i].r+1;
		ans[q[i].id] = query(q[i].r) - query(q[i].l-1);
	}
	
	Fe(i, 1, m) cout<<ans[i]<<"\n";

	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////////// Farewell! /////////////////////////