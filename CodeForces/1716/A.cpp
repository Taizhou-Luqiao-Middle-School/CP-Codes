// Date: 2022-08-04 22:35:18
// Problem: A. 2-3 Moves
// Contest: Educational Codeforces Round 133 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1716/problem/A
// Memory Limit: 256 MB
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
#define int long long
using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> PII;
void fastio(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

//////////////////// Global Variables ////////////////////

constexpr int N = 100005;

/////////////////////// Functions ////////////////////////



////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if (n == 1) 
			cout << 2;
		else
			cout << n / 3 + ((n % 3) && 1);
		cout<<"\n";
	}  	
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////
