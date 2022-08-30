// Date: 2022-07-31 10:36:13
// Problem: P5463 小鱼比可爱（加强版）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5463
// Memory Limit: 250 MB
// Time Limit: 2000 ms

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

constexpr int N = 1e6 + 5;
int  n;
lll ans;
struct item
{
    int id , v;
} a[1100000] , b[1100000];

/////////////////////// Functions ////////////////////////

inline lll read(){
	int x = 0;
	char c = getchar();
	bool y = 1;
	for(; c < '0' || c > '9'; c = getchar()) if(c=='-') y = 0;
	for(; c >= 0 && c <= '9'; c = getchar()) x = (x<<1) + (x<<3) + c - 48;
	if(y) return x;
	return -x;
}

inline void print(lll x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        print(x/10);
    putchar(x%10+'0');
}

void ms(int l, int r){
	if(l>=r) return ;
	int mid = l + r >> 1;
	ms(l, mid), ms(mid + 1, r);
	ll sum = 0ll;
	for(int i=l;i<=mid;++i){
		sum += 1ll * a[i].id;
	}
	int i = l, j = mid + 1, k = l;
	while(i<=mid && j<=r){
		if(a[i].v <= a[j].v){
			sum -= 1ll * a[i].id;
			b[k++] = a[i++];
		} else {
			ans += sum * 1ll * (n - a[j].id + 1);
			b[k++] = a[j++];
		}
	}
	if(i > mid) for(; j<=r; j++, k++){
		b[k] = a[j];
	} else {
		for(; i<=mid; i++, k++){
			b[k] = a[j];
		}
	}
	for(int i=l;i<=r;i++){
		a[i] = b[i];
	}
	
	return ;
}

void msort( int l , int r )
{
    if(l == r)
    return ;
    int mid = (l + r) >> 1;
    msort(l , mid);
    msort(mid + 1 , r);
    long long sum = 0LL;
    for(int i = l ; i <= mid ; i++ )
    {
        sum += 1ll * a[i].id;
    }
    int i = l , j = mid + 1 , k = l;
    while(1)
    {
        if(i > mid || j > r)
        break;
        if(a[i].v <= a[j].v)
        sum -= 1ll * a[i].id , b[k++] = a[i++];
        else
        {
            ans += sum * 1ll * (n - a[j].id + 1);
            b[k++] = a[j++];
        }
    }
    if(i > mid) for( ; j <= r ; j++ , k++ )
    {
        b[k] = a[j];
    }
    else for( ; i <= mid ; i++ , k++ )
    {
        b[k] = a[i];
    }
    for(int i = l ; i <= r ; i++ )
    {
        a[i] = b[i];
    }
    return ;
}

////////////////////// Main Execution ////////////////////

int main(){
  	fastio();
  	cin>>n;
  	Fe(i, 1, n) cin>>a[i].v,  a[i].id = i;
	msort(1, n);
	print(ans);
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////////// Farewell! /////////////////////////
