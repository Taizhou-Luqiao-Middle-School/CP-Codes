// Date: 2022-08-18 16:20:18
// Problem: P7076 [CSP-S2020] 动物园
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P7076
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
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
clock_t startTime;
typedef unsigned long long ull;

inline double getCurrentTime() {return (double)(clock() - startTime) / CLOCKS_PER_SEC;}
inline void fastio(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
constexpr int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
constexpr int inf = 0x3f3f3f3f;

//////////////////// Global Variables ////////////////////

constexpr int N = 1000005;
int a[N], p[N], q[N];

/////////////////////// Functions ////////////////////////

template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}

template<typename T> inline void print(T x, bool flag = 0)
{
	if(!flag && x == 0){putchar('0'); return ;}
	if (!x && flag) return ;
	if (x < 0) putchar('-'),x = -x;
	print(x / 10, 1);
	putchar(x % 10 + '0');
}

lll n, m ,c, k, se, li, ans;

////////////////////// Main Execution ////////////////////

signed main(){
  	// fastio();
  	read(n), read(m), read(c), read(k);
  	ll tmp;

  	Fe(i, 1, n){
  		read(tmp);
  		se |= tmp;
  	}

	Fe(i, 1, m){
		read(tmp);
		li |= (lll)1 << tmp;
		read(tmp);
	}
	
	F(i, 0, k){
		ans += !((li>>i) & 1) || ((se>>i) & 1);
	}
	
	print(((lll)1<<ans)-n);
	
	return 0;
}


////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////