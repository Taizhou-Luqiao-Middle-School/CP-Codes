// Date: 2022-08-18 17:33:51
// Problem: P7075 [CSP-S2020] 儒略日
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P7075
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

constexpr int N = 146097;
constexpr int ds[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int T, y[N + 10], m[N + 10], d[N + 10];
ll n, t;

/////////////////////// Functions ////////////////////////

constexpr int num(int y, int m){
	if( m==2 ) if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) return 29;
    return ds[m];
}

constexpr void init(){
	m[0]=d[0]=1;
    Fe(i, 1, N) {
        d[i] = d[i-1]+1;
        m[i] = m[i-1];
        y[i] = y[i-1];
        if(d[i] > num(y[i], m[i])) ++m[i], d[i]=1;
        if(m[i] > 12) ++y[i], m[i]=1;
    }
}

char ans[1000];

void solve(ll n){
        if(n> 2299160){
            n-= 2159351;
            t=n/N*400+1200;
            n%=N;
        }else{
            t=n/1461*4-4712;
            n%=1461;
        }
        if(t + y[n]>0) sprintf(ans, "%d %d %lld\n",d[n],m[n],t+y[n]);
        else sprintf(ans, "%d %d %lld BC\n",d[n],m[n],1-t-y[n]);
   	    cout<<ans;
}

////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
  	init();
  	cin>>T;
    while(T--){
    	cin>>n;
    	solve(n);
    }
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////
  