// Date: 2022-07-30 16:46:37
// Problem: P1966 [NOIP2013 提高组] 火柴排队
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1966
// Memory Limit: 128 MB
// Time Limit: 1000 ms

// Author: Codeboy

/////////////////////// Macros & Head ////////////////////

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

//////////////////// Global Variables ////////////////////

constexpr int N = 100005;
constexpr int mod = 1e8 - 3;
int a[N], b[N], c[N], d[N];
int cnt, n;
int mp[N], t[N];

/////////////////////// Functions ////////////////////////

bool cmpa(int i, int j){
	return a[i] < a[j];
}

bool cmpb(int i, int j){
	return b[i] < b[j];
}

// void ms(int l, int r){
	// if(l >= r) return ;
	// int mid = (l + r) / 2;
	// ms(l, mid), ms(mid + 1, r);
	// int i = l, k = 1, j = mid + 1;
	// while(i <= mid && j <= r) {
		// if(mp[i] <= mp[j]){
			// t[++k] = mp[++i];
			// i++, k++;
		// } else {
			// t[++k] = mp[++j];
			// cnt = (cnt+mid-i+1)%mod;
		// }
	// }
	// while(i <= mid) {
		// t[++k] = mp[++i];
	// }
	// while(j <= r){
		// t[++k] = mp[++j];
	// }
	// for(int i = l, j = 1 ; i <= r; i++, j++){
		// mp[i] = t[j];
	// }
// 
	// for(int i=1;i<=n;i++){
  		// cout<<mp[i]<<' ';
  	// }
// 
  	// cout<<endl;
// }

void msort(int s,int e)//归并排序; 
{
    if(s==e)return ;
    int mid=(s+e)/2;
    msort(s,mid);msort(mid+1,e);
    int i=s,k=s,j=mid+1;
    while(i<=mid && j<=e)
    {
        if(mp[i]<=mp[j])
        {
            t[k++]=mp[i++];
        }
        else
        {
            t[k++]=mp[j++];
            cnt=(cnt+mid-i+1)%mod;
        }
    }
    while(i<=mid)
    {
        t[k++]=mp[i++];
    }
    while(j<=e)
    {
        t[k++]=mp[j++];
    }
    for(int i=s;i<=e;i++)
    {
        mp[i]=t[i];
    }
}

////////////////////// Main Execution ////////////////////

int main(){
  	// fastio();
  	cin>>n;
  	Fe(i, 1, n){
  		cin>>a[i];
  		c[i] = i;
  	}
  	Fe(i, 1, n){
  		cin>>b[i];
  		d[i] = i;
  	}
  	
  	sort(c + 1, c + n + 1, cmpa), sort(d + 1, d + n + 1, cmpb);
  	
  	// memset(mp, 0, sizeof mp);

  	Fe(i, 1, n) mp[c[i]] = d[i];

  	// Fe(i, 1, n){
  		// cout<<mp[i]<<endl;
  	// }

  	msort(1, n);
  	
  	// Fe(i, 1, n){
  		// cout<<mp[i]<<endl;
  	// }
  	cout<<cnt<<endl;
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////////// Farewell! /////////////////////////
