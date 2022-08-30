// Date: 2022-07-16 19:01:56
// Problem: 数组操作
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/4498/
// Memory Limit: 256 MB
// Time Limit: 1000 ms

// Author: Codeboy

#include <bits/stdc++.h>
using namespace std;
int a[100005], m[100005], cnt;
int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
	int n, k, t;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>t;
		if(t!=0) a[cnt++] = t; 
	}
	sort(a, a+n);
	int ss = 0;
	int i;
	int kk = k;
	cnt = 0;
	for(i=0;i<n;i++){
		// cout<<a[i]<<' '<<ss<<endl;
		if(a[i]-ss>0){
			m[cnt++] = a[i]-ss;
			ss += a[i] - ss;
		}
	}
	
	for(i=0;i<min(n, k);i++){
		cout<<m[i]<<endl;
	}
	for(;i<k;i++){
		cout<<0<<endl;
	}
	return 0;
}
