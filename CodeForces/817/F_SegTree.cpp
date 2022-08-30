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
#define ls tr[rt<<1]
#define rs tr[rt<<1|1]

//////////////////// Global Variables ////////////////////

constexpr int N = 1200005, M = 100005;
int n, m;
int t[M], l[M], r[M], q[M << 2]; 
int sum[N], tag[N];

struct node{
	int l, r, tag, rev, sum;
	void init(){
		l = 0, r = 0, tag = -1, rev = 0, sum = 0;
	}
} tr[N];

/////////////////////// Functions ////////////////////////

inline void pushup(int rt){
	tr[rt].sum = rs.sum + ls.sum;
}

inline void build(int l, int r, int rt){
	tr[rt].init();
	if(l == r) return ;
	int mid = l + r >> 1;
	build(mid + 1, r, rt<<1|1);
	build(l, mid, rt<<1);
	pushup(rt);
}

inline void pushdown(int l, int r, int rt){
	int mid = l + r >> 1;
	if(tr[rt].tag != -1){
		
		ls.tag = rs.tag = tr[rt].tag;
		ls.rev = rs.rev = 0;
		
		if(tr[rt].tag){
			ls.sum = mid - l + 1;
			rs.sum = r - mid;
		} else {
			ls.sum = 0;
			rs.sum = 0;
		}
		tr[rt].tag = -1;
	}
	if(tr[rt].rev){
		if(ls.tag!=-1) ls.tag ^= 1;
		else ls.rev ^= 1;
		if(rs.tag!=-1) rs.tag ^= 1;
		else rs.rev ^= 1;
		ls.sum = mid - l + 1 - ls.sum;
		rs.sum = r - mid - rs.sum;
		tr[rt].rev = 0;
	}
}

void update(int t, int L, int R, int l, int r, int rt){
	if(L<=l&&r<=R)
	{
		if(l==r)
		{
			if(t==1) tr[rt].sum=1;
			else if(t==2) tr[rt].sum=0;
			else tr[rt].sum^=1;
		}
		else
		{
			if(t==1)
			{
				tr[rt].tag=1;
				tr[rt].rev=0;
				tr[rt].sum= r - l + 1;
			}
			if(t==2)
			{
				tr[rt].tag=0;
				tr[rt].rev=0;
				tr[rt].sum=0;
			}
			if(t==3)
			{
				if(tr[rt].tag!=-1) tr[rt].tag^=1;
				else tr[rt].rev^=1;
				tr[rt].sum= r - l + 1 - tr[rt].sum;
			}
		}
		return;
	}
	pushdown(l, r, rt);
	int mid= l + r >>1;
	if(L <= mid) update(t, L, R, l, mid, rt<<1);
	if(mid < R) update(t, L, R, mid+1, r, rt<<1|1);
	pushup(rt);
}

int query(int l, int r, int rt)
{
	if(l==r) return l;
	pushdown(l, r, rt);
	int mid = l + r >>1;
	if(ls.sum < mid - l + 1) return query(l, mid, rt<<1);
	else return query(mid+1, r, rt<<1|1);
}

////////////////////// Main Execution ////////////////////

signed main(){
  	fastio();
  	cin>>n;
  	q[++m] = 1;
  	Fe(i, 1, n){
  		cin>>t[i]>>l[i]>>r[i];
  		q[++m] = l[i], q[++m] = r[i], q[++m] = r[i] + 1;
  	}
  	
  	sort(q + 1, q + m + 1);
  	m = unique(q + 1, q + 1 + m) - q - 1;
  	build(1, m, 1);
  	Fe(i, 1, n){
  		l[i] = lower_bound(q + 1, q + 1 + m, l[i]) - q;
  		r[i] = lower_bound(q + 1, q + 1 + m, r[i]) - q;
  		update(t[i], l[i], r[i], 1, m, 1);
  		cout<<q[query(1, m, 1)]<<'\n';
  	}
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////// So long, Farewell! ////////////////////
