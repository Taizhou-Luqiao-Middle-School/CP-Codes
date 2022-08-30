// Date: 2021-10-18 15:19:43
// Problem: P1004 [NOIP2000 提高组] 方格取数
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1004
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Stauts: ACcept 13ms
// Author: Guan Yongjie

#define DEBUG 1  //调试开关
#include <bits/stdc++.h>
using namespace std;
int a[15][15],f[15][15][15][15],n;
//深搜+记忆化剪枝
int dfs(int x1,int y1,int x2,int y2){
	if(f[x1][y1][x2][y2]!=-1) return f[x1][y1][x2][y2];
	if(x1==n&&x2==n&&y1==n&&y2==n) return 0;
	int res=0;
    if (x1<n&&x2<n) res=max(res,dfs(x1+1,y1,x2+1,y2)+a[x1+1][y1]*!(x1+1==x2+1&&y1==y2)+a[x2+1][y2]);
    if (x1<n&&y2<n) res=max(res,dfs(x1+1,y1,x2,y2+1)+a[x1+1][y1]*!(x1+1==x2&&y1==y2+1)+a[x2][y2+1]);
    if (y1<n&&x2<n) res=max(res,dfs(x1,y1+1,x2+1,y2)+a[x1][y1+1]*!(x1==x2+1&&y1+1==y2)+a[x2+1][y2]);
    if (y1<n&&y2<n) res=max(res,dfs(x1,y1+1,x2,y2+1)+a[x1][y1+1]*!(x1==x2&&y1+1==y2+1)+a[x2][y2+1]);
    f[x1][y1][x2][y2]=res;
    return res;
}
int main(){
	scanf("%d",&n);
	for(int a=0;a<=n;a++)
	      for(int b=0;b<=n;b++)
	        	for(int c=0;c<=n;c++)
	         		for(int d=0;d<=n;d++) f[a][b][c][d]=-1;
	for(;;){
		int _x=0,_y=0,_v=0;
		scanf("%d%d%d",&_x,&_y,&_v);
		if(!(_x&&_y&&_v)) break;
		a[_x][_y]=_v;
	}
	printf("%d",dfs(1,1,1,1)+a[1][1]);
	return 0;
}
