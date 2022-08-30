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
int op, l, r, idx;

/////////////////////// Functions ////////////////////////



////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
  	#ifndef LOCAL
  	freopen("resort.in", "r", stdin);
  	freopen("resort.out", "w", stdout);
  	#endif
  	int T;
  	cin>>T;
  	while(T--){
  		int n, q;
  		cin>>n>>q;
  		Fe(i, 1, n) cin>>a[i];
  		if(n > 1000){
  			idx = min_element(a+1, a+n+1) - a;
	  		while(q--){
	  			cin>>op>>l>>r;
	  			if(op == 1){
	  				if(idx>=l&&idx<=r) idx = l;
	  			} else if(op == 2) {
	  				if(idx>=l&&idx<=r) idx = r;
	  			} else if(op == 3){
	  				if(idx>=l&&idx<=r) idx = r - idx + l;
				 } else {
	                    int k;
	                    cin>>k;
	                    if(idx>=l&&idx<=r) idx += k;
	                    else if(idx>=l+k&&idx<=r+k) idx -= k;
	            }
				// cout<<idx<<endl;
	  			// cout<<idx<<endl;
	  		}
	  		cout<<idx<<endl;
  		} else {
			while(q--){
	  			cin>>op>>l>>r;
	  			if(op == 1){
					sort(a+l, a+r+1, less<int>());
	  			} else if(op == 2) {
	  				sort(a+l, a+r+1, greater<int>());
	  			} else if(op == 3){
	  				reverse(a+l, a+r+1);
				 } else {
	                    int k;
	                    cin>>k;
	                    Fe(i, l, r){
	                    	swap(a[i], a[i+k]);
	                    }
	            }
				// Fe(i, 1, n){
					// cout<<a[i]<<' ';
			   // }
			   // cout<<endl;
			}
			
			cout<<min_element(a+1, a+n+1) - a<<endl;
  		}
  	}
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////