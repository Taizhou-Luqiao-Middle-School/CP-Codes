// Date: 2022-07-31 22:05:20
// Problem: A. Two 0-1 sequences
// Contest: CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/A
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

constexpr int N = 55;
string a, b;

/////////////////////// Functions ////////////////////////



////////////////////// Main Execution ////////////////////

int main(){
  	fastio();
  	int t;
  	cin>>t;
	while(t--){
		int n, m, flag = 0;
		cin>>n>>m;
		cin>>a>>b;
		if(m>n)	{
			cout<<"No"<<endl;
			continue;
		}
		if(m==n && a != b){
			cout<<"No"<<endl;
			continue;
		}
		for(int i=0;i<=n-m;i++){
			if(a[i] == b[0]) flag = 1;
		}
		int j = 1;
		for(int i=n-m+1; i<n;i++){
			if(a[i] != b[j++]) flag = 0;
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////////// Farewell! /////////////////////////
