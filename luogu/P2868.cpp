// Date: 2022-07-30 10:38:24
// Problem: P2868 [USACO07DEC]Sightseeing Cows G
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2868
// Memory Limit: 125 MB
// Time Limit: 1000 ms

// Author: Codeboy

///////////////////////Macros & Head/////////////////////

#include <bits/stdc++.h>
#define Re register
#define F(i,l,r) for(int i=l;i<r;++i)
#define Fe(i,l,r) for(int i=l;i<=r;++i)
#define Fer(i,l,r) for(int i=l;i>=r;--i)
using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> PII;
void fastio(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

//////////////////// Global Variables /////////////////////

constexpr int N = 1015;
constexpr double eps = 1e-4;
constexpr int inf = 1000010;
int f[N];
int L, R;
struct edge{
	int v, dis, nxt;
} ed[N * 5];
int head[N], cnt[N], idx;
bool vis[N];
double d[N];

/////////////////////// Functions ////////////////////////

// Add an edge to the gragh
void add(int a, int b, int dis){
	ed[++idx].nxt = head[a];
	ed[idx].v = b;
	ed[idx].dis = dis;
	head[a] = idx;
}

// Check the negitiave ring in the new gragh
bool spfacheck(double x){
	queue<int> q;
	Fe(i, 1, L){
		q.push(i);
		d[i] = 0, vis[i] = cnt[i] = 1;
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i = head[u]; i ; i = ed[i].nxt){
			int v = ed[i].v;
			double dis = (double) ed[i].dis;
			if(d[v] > d[u] + dis * x - (double) f[u]){
				d[v] = d[u] + dis * x - (double) f[u];
				if(!vis[v]){
					q.push(v);
					vis[v] = 1;
					if(++cnt[v] >= L) return 1;
				}
			}
		}
	}
	return 0;
}

////////////////////// Main Execution ////////////////////

int main(){
  	fastio();
  	cin>>L>>R;
  	Fe(i, 1, L) cin>>f[i];
  	Fe(i, 1, R){
  		int u, v, d;
  		cin>>u>>v>>d;
  		add(u, v, d);
  	}
  	
  	double l = 0, r = inf, mid;
  	
  	while(r - l > eps){
  		mid = (l + r) / 2;
  		if(spfacheck(mid)) l = mid;
  		else r = mid;
  	}
  	
	printf("%.2lf", l);
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////////// Farewell! /////////////////////////

