// Date: 2022-07-16 20:00:12
// Problem: A - Digit Sum of 2x
// Contest: AtCoder - AtCoder Regular Contest 144
// URL: https://atcoder.jp/contests/arc144/tasks/arc144_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

// Author: Codeboy

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
	int n;
	cin>>n;
	cout<<n*2<<endl;
	if(n%4!=0)
		cout<<n%4;
	for(int i=0;i<n/4;i++){
		cout<<4;
	}
	return 0;
}
