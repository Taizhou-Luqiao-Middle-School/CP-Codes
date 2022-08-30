// Date: 2022-08-01 19:05:51
// Problem: A - World Cup
// Contest: AtCoder - AtCoder Beginner Contest 262
// URL: https://atcoder.jp/contests/abc262/tasks/abc262_a
// Memory Limit: 1024 MB
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

constexpr int N = 10000;

/////////////////////// Functions ////////////////////////



////////////////////// Main Execution ////////////////////

int main(){
  	fastio();
  	int Y;
	cin>>Y;
	if(Y%4==0)cout<<Y+2<<endl;
	if(Y%4==1)cout<<Y+1<<endl;
	if(Y%4==2)cout<<Y<<endl;
	if(Y%4==3)cout<<Y+3<<endl;
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////////// Farewell! /////////////////////////
