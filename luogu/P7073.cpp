// Date: 2022-08-18 14:59:26
// Problem: P7073 [CSP-J2020] 表达式
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P7073
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
clock_t startTime = clock();
inline double getCurrentTime() {return (double)(clock() - startTime) ;}
inline void fastio(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
constexpr int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
constexpr int inf = 0x3f3f3f3f;

//////////////////// Global Variables ////////////////////

constexpr int N = 1000005;
int son[N][2];
int flag[N], c[N];
int n, q;
int a[N], ck;
int st[N], top;

/////////////////////// Functions ////////////////////////

int dfs(int u, int g){
	a[u] ^= g;
	if(u <= n){
		return a[u];
	}
	
	int x = dfs(son[u][0], g ^ flag[son[u][0]]);
	int y = dfs(son[u][1], g ^ flag[son[u][1]]);
	
	if(a[u] == 2){
		if(x == 0) c[son[u][1]] = 1;
		if(y == 0) c[son[u][0]] = 1;
		return x & y;
	} else {
		if(x == 1) c[son[u][1]] = 1;
		if(y == 1) c[son[u][0]] = 1;
		return x | y;
	}
}


void dfs2(int u) {
    if (u <= n) return;
    c[son[u][0]] |= c[u];
    c[son[u][1]] |= c[u];
    dfs2(son[u][0]);
    dfs2(son[u][1]);
}

////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
	string s;
	getline(cin, s);
	cin>>n;
    ck = n;
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    for (int i = 0; s[i]; i += 2) {
        if (s[i] == 'x') {
            int x = 0;
            i++;
            while (s[i] != ' ') {
                x = x * 10 + s[i] - '0';
                i++;
            }
            i--;
            st[++top] = x;
        } else if (s[i] == '&') {
            int x = st[top];
            --top;
            int y = st[top];
           	--top;
           	st[++top] = ++ ck;
            a[ck] = 2;
            son[ck][0] = x;
            son[ck][1] = y;
        } else if (s[i] == '|') {
            int x = st[top];
            -- top;
            int y = st[top];
            -- top;
           	st[++top] = ++ ck;
            a[ck] = 3;
            son[ck][0] = x;
            son[ck][1] = y;
        } else if(s[i] == '!'){
            flag[st[top]] ^= 1;
        }
    }
    int ans = dfs(ck, flag[ck]);
    dfs2(ck);
    cin>>q;
    while (q--) {
        int x;
		cin>>x;
       	cout<<( c[x] ? ans : !ans )<<endl;
    }
    
    return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////