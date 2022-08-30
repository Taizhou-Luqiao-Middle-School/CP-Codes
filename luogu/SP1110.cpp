// Date: 2021-10-19 10:12:26
// Problem: SP1110 SUDOKU - Sudoku
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/SP1110
// Memory Limit: 1.46 GB
// Time Limit: 2640 ms
// Stauts: ACcept
// Author: Guan Yongjie

#define DEBUG 1  //调试开关
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int Maxn=20000;
struct node{
	int x,y;
	char c;
}op[Maxn];
int m=16*16*4,l[Maxn],r[Maxn],u[Maxn],d[Maxn];// 十字链表左右上下
int idx,ansn,ans[Maxn],s[Maxn],row[Maxn],col[Maxn];
char c[20][20];
void init() // 预处理 
{	
	for(int i=0;i<=m;i++)
	{	
		l[i]=i-1;r[i]=i+1;s[i]=0;
		u[i]=d[i]=i;
	}
	l[0]=m;r[m]=0;
	idx=m+1;
}
void add(int &hd,int &tl,int x,int y)
{	
	row[idx]=x;col[idx]=y;s[y]++;
	u[idx]=y;d[idx]=d[y];u[d[y]]=idx;d[y]=idx;
	r[hd]=l[tl]=idx;r[idx]=tl;l[idx]=hd;
	tl=idx++;
}
void remove(int p)
{	
	r[l[p]]=r[p];l[r[p]]=l[p];
	for(int i=d[p];i!=p;i=d[i])
		for(int j=r[i];j!=i;j=r[j])
		{	
			s[col[j]]--;
			u[d[j]]=u[j];d[u[j]]=d[j];
		}
}
void resum(int p)
{	
	for(int i=u[p];i!=p;i=u[i])
		for(int j=l[i];j!=i;j=l[j])
		{	
			u[d[j]]=j;d[u[j]]=j;
			s[col[j]]++;
		}
	r[l[p]]=p;l[r[p]]=p;
}
bool dfs()
{	
	if(!r[0])return 1;
	int p=r[0];
	for(int i=r[0];i;i=r[i])
		if(s[i]<s[p])p=i;
	remove(p);
	for(int i=d[p];i!=p;i=d[i])
	{	
		ans[++ansn]=row[i];
		for(int j=r[i];j!=i;j=r[j])remove(col[j]);
		if(dfs())return 1;
		for(int j=l[i];j!=i;j=l[j])resum(col[j]);
		ansn--;
	}
	resum(p);
	return 0;
}
void w()
{	
	memset(r,0,sizeof(r));memset(u,0,sizeof(u));
	memset(l,0,sizeof(l));memset(u,0,sizeof(u));
	memset(s,0,sizeof(s));
	memset(col,0,sizeof(col));
	memset(row,0,sizeof(row));
}
int main()
{	int T,cases=0;
	scanf("%d",&T);
	while(T--)
	{	
		for(int i=0;i<16;i++)
			scanf("%s",c[i]);
		if(cases)printf("\n");
		cases++;
		w();
		init();
		for(int i=0,n=1;i<16;i++)
			for(int j=0;j<16;j++)
			{	
				int a=0,b=15;
				if(c[i][j]!='-')a=b=c[i][j]-'A';
				for(int k=a;k<=b;k++,n++)
				{	
					int hd=idx,tl=idx;
					op[n].x=i;op[n].y=j;op[n].c=k+'A';
					add(hd,tl,n,i*16+j+1);
					add(hd,tl,n,256+i*16+k+1);
					add(hd,tl,n,256*2+j*16+k+1);
					add(hd,tl,n,256*3+(i/4*4+j/4)*16+k+1);
				}
			}
		dfs();
		for(int i=1;i<=ansn;i++)
			c[op[ans[i]].x][op[ans[i]].y]=op[ans[i]].c;
		for(int i=0;i<16;i++)
			printf("%s\n",c[i]);
	}
	return 0;
}
/*
首先我们简化一下题目，对于一个 16×16 的矩阵，
每一行必须有 1−16，每一列必须有 1−16 
每一 16 宫格必须有 1−16

再换个说法
比如我们定义一个 (i,j,k)∈{0,1} 
表示位于 (i,j)
填的数字是否 k

也就是，对于一个 16×16
的矩阵，每一行都必须满足对于每个 k ，存在一个为 1
每一列都必须满足对于每个 k ，存在一个为 1
每一宫格都必须满足对于每个 k ，存在一个为 1

发现这就是个 DLX 精确覆盖问题
*/