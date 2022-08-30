// Date: 2022-08-20 20:04:19
// Problem: B - Plus and AND
// Contest: AtCoder - AtCoder Regular Contest 146
// URL: https://atcoder.jp/contests/arc146/tasks/arc146_b
// Memory Limit: 1024 MB
// Time Limit: 5000 ms

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

/////////////////////// Functions ////////////////////////



////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
  	int n, m, k;
  	cin>>n>>m>>k;
  	Fe(i, 1, n) cin>>a[i];
  	sort(a + 1, a + n + 1, greater<int>());
  	int idx = log2(a[1]);
  	cout<<idx<<endl;
  	while(idx >= 0){
  		int nm = m;
  		Fe(i, 1, k){
  			if(((1<<idx)&a[i])==0) nm = nm - ((1<<idx) - (a[i] & ((1<<(idx+1)) - 1)));
			
			// cout<<(1<<idx) - (a[i] & ((1<<(idx+1)) - 1))<<endl;
  		}
  		if(nm>=0) {
  			m = nm;
  			Fe(i, 1, k){
  				a[i] = (1 << idx);
  			}
  			break;
  		}
		idx -- ;
  	}
  	cout<<m<<endl;
  	if(m >= k){
  		Fe(i, 1, k){
  			a[i] += m/k; 	
  		}
  	}
  	
  	int ans = (1<<31) - 1;
  	
  	Fe(i, 1, k){
  		cout<<a[i]<<endl;
  		ans &= a[i];
  	}
  	cout<<ans<<endl;
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////