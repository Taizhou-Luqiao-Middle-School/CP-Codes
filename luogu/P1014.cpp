// Date: 2021-10-18 16:19:00
// Problem: P1014 [NOIP1999 普及组] Cantor 表
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1014
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Stauts: ACcept
// Author: Guan Yongjie

#define DEBUG 1  //调试开关
#include<iostream>
using namespace std;
int main(){
	int x,y,h=1,N,k;
	cin>>N;
	while(N>h){
	    N=N-h;
	    h++;
	}
	k=N-1;
	if(h%2==0)x=1+k,y=h-k;//判断行数是奇数还是偶数
	else x=h-k,y=1+k;
	cout<<x<<"/"<<y;
	return 0;
}
