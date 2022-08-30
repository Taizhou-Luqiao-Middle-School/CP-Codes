// Date: 2022-08-05 15:54:16
// Problem: F. MEX Queries
// Contest: Codeforces - Educational Codeforces Round 23
// URL: https://codeforces.com/problemset/problem/817/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms

// Author: Codeboy

/////////////////////// Macros & Head ////////////////////

#include <bits/stdc++.h>
#define int long long
#define Re register
#define F(i,l,r) for(int i=l;i<r;++i)
#define Fe(i,l,r) for(int i=l;i<=r;++i)
#define Fer(i,l,r) for(int i=l;i>=r;--i)
#if (__cplusplus < 201703L)
#define rF(i,l,r) for(Re int i=l;i<r;++i)
#define rFe(i,l,r) for(Re int i=l;i<=r;++i)
#define rFer(i,l,r) for(Re int i=l;i>=r;--i)
#endif
#ifndef rF
#define rF(i,l,r) F(i,l,r)
#define rFe(i,l,r) Fe(i,l,r)
#define rFer(i,l,r) Fer(i,l,r)
#endif
using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> PII;
void fastio(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
constexpr int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
constexpr int inf = 0x3f3f3f3f;

//////////////////// Global Variables ////////////////////

constexpr int N = 100005;
int n;
struct node{
	int l, r;
	mutable int val;
	bool operator < (const node &t) const{
		return l < t.l;
	}
};
typedef set<node>::iterator se;
set<node> s;
se it, itr, itl;

/////////////////////// Functions ////////////////////////

inline se split(int pos){
	it = s.lower_bound(node{pos});
	if(it != s.end() && it->l == pos) return it;
	--it;
	int l = it->l, r = it->r, v = it->val;
	s.erase(it);
	s.insert(node{l, pos - 1, v});
	return s.insert(node{pos, r, v}).first;
}

inline void assign(int l, int r, int val){
	itr = split(r + 1), itl = split(l);
	s.erase(itl, itr);
	s.insert(node{l, r, val});	
}

inline void reverse(int l, int r){
	itr = split(r + 1), itl = split(l);
	for(se it = itl; it != itr; ++ it){
		it->val=!it->val;
	}
}

////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
	cin>>n;
	s.insert(node{1, (int)1e18 + 1, 0});
	F(i, 0, n){
		int t, l, r;
		cin>>t>>l>>r;
		if(t == 1){
			assign(l, r, 1);
		} else if(t == 2){
			assign(l, r, 0);
		} else if(t == 3){
			reverse(l, r);
		}
		for(it = s.begin(); it != s.end(); ++it){
			if(!it->val){
				cout<<it->l<<"\n";
				break;
			}
		}
	}
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////
