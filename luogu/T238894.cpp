// Date: 2022-08-06 14:00:23
// Problem: T238894 奶油蛋糕
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T238894?contestId=76483
// Memory Limit: 128 MB
// Time Limit: 1000 ms

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

constexpr int N = 1005;
int st[N][N], xx[N][N], vis[N][N];
int tot;
int cx, cy;
int n,m ,x,y;
string s;

/////////////////////// Functions ////////////////////////

int calc(int now, int bef){
	return (now - bef + 1) * (now - bef) / 2;
}

////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
	// cout<<calc(6, 2)<<endl;
  	cin>>n>>m>>y>>x;
  	cin>>s;
  	cx = x , cy = y;
	st[x][y]  = 1;
	vis[x][y] = 1;
	
  	for(int i=0;i<(int)s.size();i++){
  		char c = s[i];
  		if(c == 'N'){
  			cx ++;
  		}
  		if(c == 'S'){
  			cx --;
  		}
  		if(c == 'W'){
  			cy --;
  		}
  		if(c == 'E'){
  			cy ++;
  		}
		tot += i + 1;
  		if(vis[cx][cy]==0) {
  			xx[cx][cy] = tot;
  		} else {
  			xx[cx][cy] += calc(i + 1, st[cx][cy]);
  		}
  		st[cx][cy] = i + 2;
		vis[cx][cy] = 1;
		// cout<<tot<<endl;
  		
  	}
	
	// Fer(i, n, 1){
  		// Fe(j, 1, n){
  			// cout<<st[i][j]<<' ';
  		// }
  		// cout<<'\n';
  	// }

  	Fe(i, 1, n) {
  		Fe(j, 1, n){
  			if(vis[i][j]==0) {
  				xx[i][j] = tot;
  		    } else {
  				xx[i][j] += calc(m, st[i][j]);
  		   }
  		}
  	}

  	Fer(i, n, 1){
  		Fe(j, 1, n){
  			cout<< xx[i][j] <<' ';
  		}
  		cout<<'\n';
  	}
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////
