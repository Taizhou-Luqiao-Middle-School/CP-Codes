// Date: 2022-08-11 20:14:39
// Problem: #14. 求第k大数
// Contest: Hydro
// URL: http://120.48.149.4:8888/p/14
// Memory Limit: 128 MB
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

constexpr int N = 1000005;
int a[N];

/////////////////////// Functions ////////////////////////

int quick_sort(int l, int r, int k)
{
    if (l >= r) return a[l];

    int i = l - 1, j = r + 1, x = a[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (a[i] > x);
        do j -- ; while (a[j] < x);
        if (i < j) swap(a[i], a[j]);
    }

    if (j - l + 1 >= k) return quick_sort(l, j, k);
    else return quick_sort(j + 1, r, k - (j - l + 1));
}

////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
  	int n, k;
  	cin>>n>>k;
  	F(i, 0, n) cin>>a[i];
  	cout<<quick_sort(0, n - 1, k);
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////