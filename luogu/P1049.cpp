// Date: 2022-07-30 10:26:29
// Problem: P1049 [NOIP2001 普及组] 装箱问题
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1049
// Memory Limit: 125 MB
// Time Limit: 1000 ms

// Author: Codeboy

#include <bits/stdc++.h>
#define Re register
using namespace std;
int f[20005], v[40];
int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
	
	int V;
	cin>>V;
	int n;
	cin>>n;
	
	for(Re int i=0;i<n;i++){
		cin>>v[i];
	}
	
	for(Re int i=0;i<n;i++){
		for(Re int j=V;j>=v[i];j--){
			f[j] = max(f[j], f[j-v[i]] + v[i]);
		}
	}
	
	cout<<V - f[V]<<endl;
	return 0;
}
