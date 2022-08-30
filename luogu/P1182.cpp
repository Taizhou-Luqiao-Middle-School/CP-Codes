// Date: 2022-07-31 10:05:55
// Problem: P1182 数列分段 Section II
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1182
// Memory Limit: 125 MB
// Time Limit: 1000 ms

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

constexpr int N = 100005;
int n, m;
int a[N];

/////////////////////// Functions ////////////////////////

bool check(int x){
	int cnt = 0, sum = 0;
	F(i, 0, n){
		if(sum + a[i] <= x) sum += a[i];
		else sum = a[i], ++ cnt; 
	}
	return cnt >= m;
}

////////////////////// Main Execution ////////////////////

int main(){
  	fastio();
  	cin>>n>>m;
  	int l = 0, r = 0, mid;
  	F(i, 0, n) cin>>a[i], l = max(l, a[i]), r += a[i];
  	while(l <= r){
  		mid = l + r >> 1;
  		if(check(mid)) l = mid + 1;
  		else r = mid - 1;
  	}
  	
  	cout<<l<<endl;
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////////// Farewell! /////////////////////////
