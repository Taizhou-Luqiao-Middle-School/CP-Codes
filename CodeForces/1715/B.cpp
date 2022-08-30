// Date: 2022-08-20 22:35:16
// Problem: B. Beautiful Array
// Contest: Codeforces Round #816 (Div. 2)
// URL: https://codeforces.com/contest/1715/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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

/////////////////////// Functions ////////////////////////



////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
  	int t;
  	cin>>t;
  	while(t--){
  		ll n, k, b, s;
  		cin>>n>>k>>b>>s;
  		if(s > b * k + (k-1) * n) cout<< -1 ;
  		else if(s/k < b) cout<< -1 ;
  		else {
  			ll i = 0, sum = min(s, k * b + k - 1);
  			s -=  sum;
  			cout<<sum<<' ';
  			for(;i<n&&s>=k;++i){
  				if(s >= k){
  					cout<< k-1 <<' ';
  					s -= (k - 1);
  				} else {
  					cout<<s<<' ';
  					break;
  				}
  			}
  			if(s>0) {
  				cout<<s<<' ';
  				i++;
  			}
  			for(;i<n-1;i++){
  				cout<<'0'<<' ';
  			}
  		}
  		cout<<endl;
  	}
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////