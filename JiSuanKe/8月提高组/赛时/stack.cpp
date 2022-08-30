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

constexpr int N = 1000005, mod = 998244353;

/////////////////////// Functions ////////////////////////

unsigned long long ctl[N] = {1,1};
int qmi(int a, int b, int mod)
{
    a %= mod;
    if (!a)
    {
        return 0;
    }
    int result = 1;
    for (; b; a = 1ll * a * a % mod, b >>= 1)
    {
        if (b & 1)
        {
            result = 1ll * result * a % mod;
        }
    }
    return result;
}

void calc()
{
    unsigned long long i;
    for(i = 2; i < N; i ++)
        ctl[i] = (ctl[i-1]*(4*i-2)%mod)*qmi(i+1, mod - 2, mod) % mod;
}

int n, f[N];
int fac[N << 1];
int inv[N << 1];

int C(const int n, const int m)
{
    if (n < m)
    {
        return 0;
    }
    return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int cal(int a, int b)
{
    return (1ll * C(a + 2 * b, b) - C(a + 2 * b, b - 1) + mod) % mod;
}
void init(const int n)
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = 1ll * fac[i - 1] * i % mod;
    }
    inv[n] = qmi(fac[n], mod - 2, mod);
    for (int i = n - 1; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * (i + 1ll) % mod;
    }
}
int main()
{
	#ifndef LOCAL
  	freopen("stack.in", "r", stdin);
  	freopen("stack.out", "w", stdout);
  	#endif
	init(1000000);
    calc();
    int n;
    cin>>n;
    // Fe(i, 1, n){
    	// cout<<ctl[i - 1]<<' ';
    	// // cout<<cal(0, i - 1)<<endl;
    // }
    cout<<ctl[n - 1]<<endl;
}

////////////////////// Main Execution ////////////////////


////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////