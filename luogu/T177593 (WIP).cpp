// Date: 2022-08-14 14:00:35
// Problem: T177593 「GLR-R3」立春
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T177593?contestId=78025
// Memory Limit: 128 MB
// Time Limit: 1000 ms

// Author: Codeboy

/////////////////////// Macros & Head ////////////////////

#include <bits/stdc++.h>
#define int long long
#define Re register
#define F(i,l,r) for(int i=l;i<r;++i)
#define Fe(i,l,r) for(int i=l;i<=r;++i)
#define Fer(i,l,r) for(int i=l;i>=r;--i)
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

constexpr int N = 100005, mod = 1e9 + 7;
int ans = 1;

/////////////////////// Functions ////////////////////////

int f[501][20001];
void init(){
    f[1][0]=1;
    for(Re int i=2;i<=301;i++){
        ll sum=0;
        for(Re int j=0;j<=i*(i-1)/2;j++){
             sum=(sum+f[i-1][j])%mod;
             if(j>=i) sum=(sum-f[i-1][j-i]+mod)%mod;
             f[i][j]=sum;
        }
    }
}

////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
  	init();
  	int n;
  	cin>>n;
  	int tmp = 1, k = (n - 1), tt;
	// cout<<n * (n - 1) / 2<<endl;
	int ddff = n * (n - 1) / 2;
	rF(i, 1, ddff){
		tmp = (tmp * 2) % mod;
		// cout<<tmp<<endl;
		// k = (k * 2) % mod;
		ans =  (tmp * f[n][i] % mod + ans) % mod;
		// cout<<ans<<endl;
		// cout<<k<<' ';
		// cout<<ans<<endl;
	}
	if(n>2) ans = (ans + tmp * 2 % mod) % mod;
	cout<<ans<<endl;
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////