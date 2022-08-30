// Date: 2022-08-05 15:47:46
// Problem: P2197 【模板】nim 游戏
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2197
// Memory Limit: 125 MB
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
constexpr int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
constexpr int inf = 0x3f3f3f3f;

//////////////////// Global Variables ////////////////////

constexpr int N = 100005;

/////////////////////// Functions ////////////////////////



////////////////////// Main Execution ////////////////////

int main(){
  	fastio();
  	int t;
  	cin>>t;
  	while(t--){
  		int n;
  		cin>>n;
  		int ans = 0;
  		F(i, 0, n){
  			int a;
  			cin>>a;
  			ans ^= a;
  		}
  		if(ans==0) cout<<"No"<<endl;
  		else cout<<"Yes"<<endl;
  	}
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////
