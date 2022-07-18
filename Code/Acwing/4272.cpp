// Date: 2022-07-18 19:41:09
// Problem: 校庆
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/4272/
// Memory Limit: 64 MB
// Time Limit: 8000 ms

// Author: Codeboy

#include <bits/stdc++.h>
using namespace std;
string xy, lb;
int cnt;
string max(string a, string b){
	int A = 0, B = 0;
	for(int i=6;i<14;i++){
		A = 10 * A+ a[i] - '0';
		B = 10* B + b[i] -'0';
	}
	if(A>B) return b;
	return a;
}

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
	int n, m;
	cin>>n;
	unordered_map<string, bool> map;
	string s;
	while(n--){
		cin>>s;
		map[s] = 1;
	}
	cin>>m;
	while(m--){
		cin>>s;
		if(map[s]){
			if(xy.size()) xy = max(xy, s);
			else xy = s;
			cnt ++;
		}
		else {
			if(lb.size()) lb = max(lb, s);
			else lb = s;
		}
	}
	cout<<cnt<<endl;
	if(cnt) cout<<xy<<endl;
	else cout<<lb<<endl;
	return 0;
}
