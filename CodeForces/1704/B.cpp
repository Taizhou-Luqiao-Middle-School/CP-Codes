// Date: 2022-07-31 22:05:21
// Problem: B. Luke is a foodie
// Contest: CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/B
// Memory Limit: 256 MB
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

constexpr int N = 200005;
int a[N];

/////////////////////// Functions ////////////////////////



////////////////////// Main Execution ////////////////////

int main(){
  	fastio();
  	int t;
  	cin>>t;
  	while(t--){
  		// cout<<endl;
  		int n, x, cnt = 0;
  		cin>>n>>x;
  		F(i, 0, n) cin>>a[i];
		int l = a[0] - x, r = a[0] + x;
		for(int i=1;i<n;i++){
			int nl = a[i] - x, nr = a[i] + x;
			// cout<<nl<<' '<<nr<<' '<<l<<' '<<r<<endl;
			if(nl>r){
				r = nr;
				l = nl;
				cnt++;
				continue;
			} else if(nr<l){
				r = nr;
				l = nl;
				cnt++;
				continue;
			};
			if(nr < r) {
				r = nr;
			} else if(nl > l) {
				l = nl;
			}
		}
		cout<<cnt<<endl;
  	}
	
	
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////////// Farewell! /////////////////////////
