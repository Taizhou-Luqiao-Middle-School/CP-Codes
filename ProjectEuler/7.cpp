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

constexpr int N = 1000005;
int st[N], prime[N], cnt; 

/////////////////////// Functions ////////////////////////

void primeseive(int n){
	int i = 1;
	while(cnt <= n){
		i ++ ;
		if(!st[i]) prime[cnt++] = i;
		for(int j=0;prime[j] * i <= 1000005 ; j++){
			st[prime[j] * i] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}

////////////////////// Main Execution ////////////////////

int main(){
  	fastio();
  	primeseive(10005);
  	cout<<cnt<<endl;
  	for(int i=0;i<10001;i++){
  		cout<<prime[i]<<endl;
  	}
  	cout<<prime[10000]<<endl;
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////////// Farewell! /////////////////////////
