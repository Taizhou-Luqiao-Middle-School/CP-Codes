// Date: 2022-07-31 20:53:15
// Problem: P1439 【模板】最长公共子序列
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1439
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
int mp[N], b[N];
int n;

/////////////////////// Functions ////////////////////////

int read(){
	int x;
	cin>>x;
	return x;
}

////////////////////// Main Execution ////////////////////

int main(){
	memset(b, 0x3f, sizeof b);
  	fastio();
  	cin>>n;
  	Fe(i, 1, n) mp[read()] = i;
  	Fe(i, 1, n)	{
  		int x = mp[read()];
  		*lower_bound(b + 1, b + n + 1, x) = x;
  	}
  	cout<<lower_bound(b + 1, b + n + 1, b[0]) - b - 1<<endl;
  	
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////////// Farewell! /////////////////////////
