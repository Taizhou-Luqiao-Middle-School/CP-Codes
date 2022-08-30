// Date: 2022-07-30 21:11:09
// Problem: T169190 T1
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T169190
// Memory Limit: 512 MB
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

constexpr int N = 10000;

/////////////////////// Functions ////////////////////////

void print(int n)
{
    string r;
    while (n != 0){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
	reverse(r.begin(), r.end());
    cout<< r <<endl;
}

////////////////////// Main Execution ////////////////////

int main(){
  	fastio();
  	string s;
  	cin>>s;
  	int len = s.size();
  	unordered_set<int> m;
  	int mxl = log2(len) + 1;
  	// cout<<mxl<<endl;
  	for(int i=1;i<=mxl;i++){
  		for(int j = 0; j + i < len; j++){
  			int t = 1, r = 0;
  			for(int k = j + i; k >= j; k --){
  				r += ( s[k] - '0' ) * t;
  				t *= 2;
  				m.emplace(r);
  				// cout<<r<<endl;
  			}
  		}
  	}
  	// cout<<endl;
  	int ans = 0;
  	for(int i=0;i<=1<<mxl;i++){
  		if(m.count(i) == 0){
  			ans = i;
  			break;
  			// cout<<i<<endl;
  			// print(i);
  		}
  	}
  	print(ans);
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////////// Farewell! /////////////////////////
