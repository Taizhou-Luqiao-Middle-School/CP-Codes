// Date: 2022-08-16 22:35:15
// Problem: C. Fighting Tournament
// Contest: Codeforces Round #814 (Div. 2)
// URL: https://codeforces.com/contest/1719/problem/C
// Memory Limit: 256 MB
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

constexpr int N = 100005;
int b[N], c[N];
PII que[N];

/////////////////////// Functions ////////////////////////

struct node{
	int v, id;
};
deque<node> a(N);

////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
  	int t;
  	cin>>t;
	node tmp;
  	int n, q;

  	while(t--){
  		a.clear();
		memset(c, 0x3f, sizeof c);
		// vector<node> a(n+1);
		cin>>n>>q;
  		Fe(i, 1, n) {
  			cin>>tmp.v;
  			tmp.id = i;
  			a[i] = tmp;
  		}
		Fe(i, 1, q){
			cin>>que[i].fi>>que[i].se;
		}
		// sort(que + 1, que + q +1);
		int k = 0, idx = 1;
  		while(a[1].v != n){
			++k;
			// cerr<<a[1].v<<endl;
  			if(a[1].v > a[2].v){
				b[a[1].id]++;
				c[a[1].id] = k;
  				node t2 = a[2], t1 = a[1];
				a.pop_front();a.pop_front();
				a.push_front(t1);
				a.push_back(t2);
  				// for(int i =2; i < n; i++){
  					// a[i] = a[i + 1];
  				// }
  				// a[n] = t;
  				// a.erase(a.begin() + 2);
  				// a.pb(t);
  			} else {
  				b[a[2].id]++;
				c[a[2].id] = k;
				node t = a[1];
				a.pop_front();
				a.push_back(t);
  				// for(int i =2; i < n; i++){
  					// a[i] = a[i + 1];
  				// }
  				// a[n] = t;
  				// a.erase(a.begin() + 1);
  				// a.pb(t);
  			}
  		}
  		// cout<<c[4]<<endl;
		Fe(i, 1, q){
			if(que[i].fi==a[1].id){
				cout<<b[a[1].id] + que[i].se - k<<endl;
			} else {
				// cout<<que[i].fi<<endl;
				if(que[i].se >= c[que[i].fi]) cout<<1<<endl;
				else cout<<0<<endl;
			}
		}
		
  	}
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////