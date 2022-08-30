// Date: 2021-10-18 20:08:16
// Problem: P1013 [NOIP1998 提高组] 进制位
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1013
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Stauts :ACcept 11ms
// Author: Guan Yongjie

#define DEBUG 1  //调试开关
#include<bits/stdc++.h>

using namespace std;

int n,ans[15],mp[26]; //每个数的值记为 ans[], 字母与数字的对应关系记为 mp[]
char s[15][15][3];

inline bool check(int x,int y) //检验 (x,y)
{
    int sum=ans[x]+ans[y]; //和
    int cur=s[x][y][1]-'A'; //处理十位
    if (sum>=n-1 && mp[cur]!=1) return 0; //如果和 >=n-1 但没有进位
    if (sum>=n-1) sum%=(n-1),cur=s[x][y][2]-'A'; //处理个位
    if (mp[cur]!=sum) return 0; //不相等
    return 1;
}

signed main()
{
    scanf("%d",&n);
    for (int j=1;j<=n;j++) scanf("%s",s[1][j]+1);
    for (int i=2;i<=n;i++)
    {
        int cnt=0;
        for (int j=1;j<=n;j++)
        {
            scanf("%s",s[i][j]+1);
            if(strlen(s[i][j]+1)>=2)
            	cnt++;
        }
        ans[i]=cnt;
        mp[s[i][1][1]-'A']=cnt;
    }
    for (int i=2;i<=n;i++) 
    	for (int j=2;j<=n;j++) 
    		if (!check(i,j)) {
    			printf("ERROR!");
    			return 0;
    		}	
    for (int i=2;i<=n;i++)
    	printf("%c=%d ",s[i][1][1],ans[i]);
    printf("\n%d",n-1);
    return 0;
}


/*
Proof:
	因为有 N 个不同的数，所以最少 N 进制。
	
	假设为 N+1 进制，那么一定有一个数没有出现，假设为 k 。
	
	    k=0 或 k=1，而 1+N=10，矛盾。
	    1<k≤N，而 1+(k−1)=k ，矛盾。
	
	其它 >N 进制的情况同理，所以一定是 N 进制，结论 1 得证。
	
	数字为 0..N−1 ，所以结论 2 显然。
*/