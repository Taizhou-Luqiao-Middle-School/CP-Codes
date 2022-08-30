// Date: 2021-10-18 16:08:36
// Problem: P1047 [NOIP2005 普及组] 校门外的树
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1047
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Stauts: ACcept
// Author: Guan Yongjie

#define DEBUG 1  //调试开关
#include <bits/stdc++.h>
using namespace std;
int r[10005],l,m;
int main(){
	cin>>l>>m;
	for(int i=0;i<=l;i++) r[i]=1;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		for(int j=x;j<=y;j++){
			r[j]=0;
		}
	}
	int lefttrees=0;
	for(int i=0;i<=l;i++){
		if(r[i]) lefttrees++;
	}
	cout<<lefttrees<<endl;
	return 0;
}
/*
入门题一遍过
*/