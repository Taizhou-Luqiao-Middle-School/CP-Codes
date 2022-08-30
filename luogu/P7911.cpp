// Date: 2022-08-15 20:50:43
// Problem: P7911 [CSP-J 2021] 网络连接
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P7911
// Memory Limit: 512 MB
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

constexpr int N = 1005;
int len = 0;
struct str{
	string ad;
	int id;
} s[N];

/////////////////////// Functions ////////////////////////

bool check(int x){
	return (x>=0&&x<=255);
}

bool check(string ad){
	int cnt1 = 0, cnt2 = 0;
	F(i, 0, ad.length()){
		if(ad[i] == '.') ++cnt1;
		if(ad[i] == ':') ++cnt2;
	}
	if(cnt1 != 3 || cnt2 != 1) return false;
	long long a, b, c, d, e;
	char tmp[1000];
	sscanf(ad.c_str(), "%lld.%lld.%lld.%lld:%lld", &a, &b, &c, &d, &e);
	sprintf(tmp, "%lld.%lld.%lld.%lld:%lld", a, b, c, d, e);
	if(check(a) && check(b) && check(c) && check(d) && e >= 0 && e <=65565) {
		if(!strcmp(ad.c_str(), tmp)) return true;
		else return false;
	} else {
		return false;
	}
}

////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
  	int n;
  	cin>>n;
  	string op, ad;

  	Fe(i, 1, n){
  		cin>>op>>ad;
  		if(!check(ad)){
  			cout<<"ERR"<<endl;
  		} else {
  			if(op == "Server"){
  				bool f = 1;
  				Fe(j, 1, len){
  					if(s[j].ad == ad){
  						f = 0;
  						break;
  					}
  				}
  				if(f){
  					len ++;
  					s[len].ad = ad;
  					s[len].id = i;
  					cout<<"OK"<<endl;
  				} else {
  					cout<<"FAIL"<<endl;
  				}
  			} else {
  				bool f = 1;
  				Fe(j, 1, len){
  					if(s[j].ad == ad){
  						f = 0;
  						cout<<s[j].id<<endl;
  						break;
  					}
  				}
  				if(f){
  					cout<<"FAIL"<<endl;
  				}
  			}
  		}
		
  	}
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////