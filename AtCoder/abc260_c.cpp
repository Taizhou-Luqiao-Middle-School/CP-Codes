// Date: 2022-07-17 20:00:29
// Problem: C - Changing Jewels
// Contest: AtCoder - AtCoder Beginner Contest 260
// URL: https://atcoder.jp/contests/abc260/tasks/abc260_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

// Author: Codeboy

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[40], b[40];
int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
	int n, x, y;
	cin>>n>>x>>y;
	if(n==1) {cout<<0<<endl;return 0;}
	a[n] = 1;
	for(int i=n;i>1;i--){
		b[i] = a[i] * x; 
		a[i-1] = a[i] + b[i];
		b[i-1] = a[i-1] * x + y * b[i];
	}
	cout<<b[1]<<endl;
	return 0;
}
