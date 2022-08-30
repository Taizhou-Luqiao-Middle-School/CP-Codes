// Date: 2022-07-18 21:39:16
// Problem: 水仙花数
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/3647/
// Memory Limit: 64 MB
// Time Limit: 1000 ms

// Author: Codeboy

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
	int m, n;
	while(cin>>m>>n, m){
		bool flag = 0;
		for(int i=m;i<=n;i++){
			int r, s = 0, t = i;
			while(t){
				r = t % 10;
				t /= 10;
				s += r * r * r;
			}
			if(s == i){
				cout<<i<<' ';
				flag = 1;
			}
		}
		if(flag==0) cout<<"no";
		cout<<endl;
		
	}
	return 0;
}
