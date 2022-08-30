// Date: 2022-07-17 20:00:22
// Problem: A - A Unique Letter
// Contest: AtCoder - AtCoder Beginner Contest 260
// URL: https://atcoder.jp/contests/abc260/tasks/abc260_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

// Author: Codeboy

#include <bits/stdc++.h>
using namespace std;
	int x[1000];

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
	string s;
	cin>>s;
	for(auto i:s){
		x[i]++;
	}
	for(int i=0;i<1000;i++){
		if(x[i]==1) {
			cout<<char(i)<<endl;
			return 0;
		}
	}
	cout<<"-1"<<endl;
	return 0;
}
