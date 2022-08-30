// Date: 2022-08-06 20:03:49
// Problem: B - Ancestor
// Contest: AtCoder - LINE  Verda Programming Contest（AtCoder Beginner Contest 263）
// URL: https://atcoder.jp/contests/abc263/tasks/abc263_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

// Author: Codeboy

/////////////////////// Macros & Head ////////////////////

#include <bits/stdc++.h>
// #define int long long
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
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> PII;
clock_t startTime;
inline double getCurrentTime() {return (double)(clock() - startTime) / CLOCKS_PER_SEC;}
inline void fastio(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
constexpr int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
constexpr int inf = 0x3f3f3f3f;

//////////////////// Global Variables ////////////////////

constexpr int N = 100005;
int p[N];
/////////////////////// Functions ////////////////////////



////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
  	int n;
  	cin>>n;
  	Fe(i, 2, n) cin>>p[i];
  	int cur = p[n];
  	int cnt = 0;
  	while(cur != 1){
  		cur = p[cur];
  		cnt ++;
  	}
  	cout<<cnt + 1<<endl;
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////
