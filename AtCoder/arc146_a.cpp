// Date: 2022-08-20 20:00:15
// Problem: A - Three Cards
// Contest: AtCoder - AtCoder Regular Contest 146
// URL: https://atcoder.jp/contests/arc146/tasks/arc146_a
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
#define sFe(i,l,r) for(int i=l,_##i=r;i<=_##i;++i)
#define sFer(i,r,l) for(int i=r,_##i=l;i>=_##i;--i)
#define sF(i,l,r) for(int i=l,_##i=r;i<_##i;++i)
#if __cplusplus < 201703L
#define rF(i,l,r) for(Re int i=l;i<r;++i)
#define rFe(i,l,r) for(Re int i=l;i<=r;++i)
#define rFer(i,l,r) for(Re int i=l;i>=r;--i)
#else
#define rF(i,l,r) F(i,l,r)
#define rFe(i,l,r) Fe(i,l,r)
#define rFer(i,l,r) Fer(i,l,r)
#endif
#if __x86_64__ || __ppc64__
typedef __int128 lll;
#else
typedef long long lll;
#endif
#ifndef LOCAL
#define endl '\n'
#endif
#define all(x) (x).begin(),(x).end()
#define enr(i, u) for(int i=h[u];i;i=ne[i])
#define chmax(a, b) if((a)<(b)){(a)=(b);}
#define chmin(a, b) if((a)>(b)){(a)=(b);}
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
clock_t startTime;
inline double getCurrentTime() {return (double)(clock() - startTime) / CLOCKS_PER_SEC;}
inline void fastio(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
constexpr int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
constexpr int inf = 0x3f3f3f3f;

//////////////////// Global Variables ////////////////////

constexpr int N = 200005;
int a[N];
int b[10];
PII c[10];

/////////////////////// Functions ////////////////////////

bool cmp(int i, int j){
	if(i / max(1, (int)(pow(10, ((int)log10(i))))) == j / max(1, (int)(pow(10, ((int)log10(j)))))){
		int t = 0;
		while(i / max(1, (int)(pow(10, ((int)log10(i)-t)))) == j / max(1, (int)(pow(10, ((int)log10(j)-t))))){
			t ++;
		}
		
	}
	if(i / max(1, (int)(pow(10, ((int)log10(i))))) > j / max(1, (int)(pow(10, ((int)log10(j)))))) return true;
	else return false;
}

////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
  	int n;
  	cin>>n;
  	F(i, 0, n) cin>>a[i];
  	sort(a, a + n, greater<int>());
	
	// cout<<(int)log10(a[0])<<endl;
	int cc = max((int)log10(a[0]), max((int)log10(a[1]), (int)log10(a[2])));
	if(cc != 0){
		b[0] = a[0] * (int)pow(10, cc - (int)log10(a[0]));
		b[1] = a[1] * (int)pow(10, cc - (int)log10(a[1]));
		b[2] = a[2] * (int)pow(10, cc - (int)log10(a[2]));
	}
	
	// cout<<b[0]<<b[1]<<b[2]<<endl;
	F(i, 0, 3){
		c[i] = mp(b[i], a[i]);
	}
	sort(c, c + 3, greater<PII>());
	F(i, 0, 3){	
		cout<<c[i].se;
	}
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////