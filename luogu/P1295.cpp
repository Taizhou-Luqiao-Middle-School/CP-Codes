// Date: 2022-08-14 20:54:54
// Problem: P1295 [TJOI2011] 书架
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1295
// Memory Limit: 125 MB
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

constexpr int N = 100005;
int a[N],f[N],qu[N],qi[N],lst[N],rst[N];
int lt,rt,s=1,t,mid;
//a数字，f最优解，qi单降队列在a的下标，qu对qi每个的f值，lst左单调栈在qu的下标，rst表示右

/////////////////////// Functions ////////////////////////

void pushle(int x){
    if(!lt||qu[lst[lt]]>qu[x]) lst[++lt]=x;
} //左端插入

void pushri(int x){
    if(!rt||qu[rst[rt]]>qu[x]) rst[++rt]=x; 
} //右端插入

void rebuild(){
    mid = s+t >> 1;lt = rt = 0;
    Fer(i,mid,s) pushle(i);
    Fe(i,mid+1,t) pushri(i);
}//重构单调栈

////////////////////// Main Execution ////////////////////

signed main(){
	fastio();
  	//f[i]=f[j]+max(a[j+1]...a[i])(s[i]-s[j]<=m)动归方程
    int n, m, st=1, sum=0;
    cin>>n>>m;
    Fe(i, 1, n){
		cin>>a[i];
        sum+=a[i];
        while(sum>m) sum-=a[st++]; //维护st
        while(s<=t && a[qi[t]]<=a[i]) {
            if(rt && rst[rt]==t) rt--;
            if(lt && lst[lt]==t) lt--;
            if(--t <= mid) rebuild();
		} //维护单调队列
		qi[++t] = i;
		if(s == t)
			qu[t] = f[st-1] + a[i];
		else
			qu[t] = f[qi[t-1]] + a[i];
		pushri(t); //加入当前元素
        if(lst[lt]==s) lt--;
        if(rst[rt]==s) rt--; //将a[q1]排除（不符合f[a[qj]]+a[q[j+1]]规律）
        while(s<=t && qi[s]<st) {
            if(rt && rst[rt] == s) rt--;
            if(lt && lst[lt] == s) lt--;
            if(++s > mid) rebuild();
		} //弹出过期元素
        f[i]=a[qi[s]]+f[st-1];
        if(lt) f[i]=min(f[i],qu[lst[lt]]); 
        if(rt) f[i]=min(f[i],qu[rst[rt]]); //转移
    }
    cout<<f[n]<<endl;
    return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything Feres well. ////////////////

////////////////// So long, Farewell! ////////////////////