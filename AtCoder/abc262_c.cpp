// Date: 2022-08-01 19:18:00
// Problem: C - Min Max Pair
// Contest: AtCoder - AtCoder Beginner Contest 262
// URL: https://atcoder.jp/contests/abc262/tasks/abc262_c
// Memory Limit: 1024 MB
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

constexpr int N = 500005;
int a[N];

/////////////////////// Functions ////////////////////////



////////////////////// Main Execution ////////////////////

int main(){
  	fastio();
  	int n;
  	cin>>n;
  	F(i, 0, n) cin>>a[i];
    ll cnt = 0;
    F(i, 0, n) {
        a[i] -= 1;
        if (a[i] == i) {
            cnt += 1;
        }
    }

    ll ans = cnt * (cnt - 1) / 2;

    F(i, 0, n) {
        if (a[i] > i && a[a[i]] == i) {
            ans += 1;
        }
    }

    cout << ans << '\n';
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////////// Farewell! /////////////////////////
