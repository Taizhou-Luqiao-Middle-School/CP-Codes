// Date: 2021-10-18 15:59:50
// Problem: P1046 [NOIP2005 普及组] 陶陶摘苹果
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1046
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Stauts: ACcept
// Author: Guan Yongjie

#define DEBUG 1  //调试开关
#include <bits/stdc++.h>
using namespace std;
int a[12];
int main(){
	for(int i=0;i<10;i++){
		cin>>a[i];
	}
	int height;
	cin>>height;
	int ans=0;
	for(int i=0;i<10;i++){
		if(height+30>=a[i]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
/*
PS:如果不是因为LG首页空了一题不好看，我是不屑于写的
我写这句话的时间都超过了AC的时间，hh
*/