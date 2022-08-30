// Date: 2022-08-11 09:56:24
// Problem: P1005 [NOIP2007 提高组] 矩阵取数游戏
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1005
// Memory Limit: 125 MB
// Time Limit: 1000 ms

// Author: Codeboy

/////////////////////// Macros & Head ////////////////////

#include <bits/stdc++.h>
// #define int long long
#define Re register
#define F(i,l,r) for(int i=l;i<r;++i)
#define Fe(i,l,r) for(int i=l;i<=r;++i)
#define Fer(i,l,r) for(int i=l;i>=r;--i)
#if __cplusplus < 201703L
#define rF(i,l,r) for(Re int i=l;i<r;++i)
#define rFe(i,l,r) for(Re int i=l;i<=r;++i)
#define rFer(i,l,r) for(Re int i=l;i>=r;--i)
#endif
#ifndef rF
#define rF(i,l,r) F(i,l,r)
#define rFe(i,l,r) Fe(i,l,r)
#define rFer(i,l,r) Fer(i,l,r)
#endif
#if __x86_64__ || __ppc64__
typedef __int128 lll;
#else
typedef long long lll;
#endif
#define all(x) (x).begin(),(x).end()
#define enr(i, u) for(int i=h[u];i;i=ne[i])
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

constexpr int N = 500;
lll f[N][N], ans,  a[N][N];

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

/////////////////////// Functions ////////////////////////

lll qpow(lll a, lll b){
	lll res = 1;
	while(b){
		if(b & 1) res = res * a;
		b >>= 1;
		a = a * a; 
	}
	return res;
}

lll dp(int l, int r, int row, int step){
	if(f[l][r]) return f[l][r];
	if(l > r) return 0;
	f[l][r] = max(dp(l + 1, r, row, step + 1) + a[row][l] * qpow(2, step),
				  dp(l, r - 1, row, step + 1) + a[row][r] * qpow(2, step));
	return f[l][r];
}

////////////////////// Main Execution ////////////////////

signed main(){
	int n, m;
	read(n), read(m);
	Fe(i, 1, n){
		Fe(j, 1, m) read(a[i][j]);
	}

	Fe(i, 1, n){
		memset(f, 0, sizeof f);
		ans = ans + dp(1, m, i, 1);
	}
	
	print(ans);

	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////