// Date: 2022-08-12 16:59:32
// Problem: P1725 琪露诺
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1725
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
int a[N], n, l, r;
int f[N];
int que[N], head = 1, tail = 1;
ll ans;

/////////////////////// Functions ////////////////////////

inline void insert(int x){
	while(f[x] >= f[que[tail]] && tail >= head) tail -- ;
	que[++ tail] = x;
}

inline int query(int x){
	while(que[head] + r < x) head ++;
	return que[head];
}

////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
  	memset(f, 128, sizeof f);
  	f[0] = 0, ans = -inf;
  	cin>>n>>l>>r;
  	Fe(i, 0, n) cin>>a[i];
  	Fe(i, l ,n){
  		insert(i - l);
  		int pre = query(i);
  		f[i] = f[pre] + a[i];
  		if(i + r > n) chmax(ans, f[i]);
  	}
  	
  	cout<<ans<<endl;
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////