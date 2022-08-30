// Date: 2022-07-19 09:17:20
// Problem: A. Another String Minimization Problem
// Contest: Codeforces - Codeforces Round #809 (Div. 2)
// URL: https://codeforces.com/contest/1706/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms

// Author: Codeboy

#include <bits/stdc++.h>
using namespace std;
int n, m;
int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		string s(m, 'B');
		
		while(n--){
			int x;
			cin>>x;
			x = min(x - 1, m - x);
			
			if(s[x]=='B') s[x] = 'A';
			else s[m - x - 1] = 'A'; 
		}
		cout<<s<<endl;
	}
	
	return 0;
}
