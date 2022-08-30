// Date: 2021-10-18 10:26:28
// Problem: P4342 [IOI1998]Polygon
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4342
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Stauts: Accept 16ms
// Author: Guan Yongjie

#define DEBUG 1  //调试开关
#include<bits/stdc++.h>
#define ll long long
const int inf=0x3f3f3f3f;
int n,ans=-inf;
int a[105];
int f[150][150],g[150][150];
char c[105];
int max(int x,int y){return (x>y)?(x):(y);}
int min(int x,int y){return (x<y)?(x):(y);}
int main(){
    scanf("%d\n",&n);//读入很诡异
    for(int i=1;i<=n;i++){
        scanf("%c %d",&c[i],&a[i]);getchar();
        a[n+i]=a[i];c[n+i]=c[i];//断环为链
    }
    for(int i=1;i<=(n<<1);i++){
        for(int j=1;j<=(n<<1);j++){
            f[i][j]=-inf,g[i][j]=inf;
        }
    }
    for(int i=1;i<=(n<<1);i++)f[i][i]=g[i][i]=a[i];
    for(int len=2;len<=n;len++){
        for(int i=1,j=len;j<=(n<<1);i++,j++){
            for(int k=i;k<j;k++){ //区间dp 
                if(c[k+1]=='x'){ //乘法情况 
                    f[i][j]=max(f[i][j],max(f[i][k]*f[k+1][j],max(g[i][k]*g[k+1][j],max(f[i][k]*g[k+1][j],g[i][k]*f[k+1][j]))));
                    g[i][j]=min(g[i][j],min(f[i][k]*f[k+1][j],min(g[i][k]*g[k+1][j],min(f[i][k]*g[k+1][j],g[i][k]*f[k+1][j]))));
                }
                else if(c[k+1]=='t'){ //加法情况 
                    f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]);
                    g[i][j]=min(g[i][j],g[i][k]+g[k+1][j]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++)ans=max(ans,f[i][i+n-1]);printf("%d\n",ans);
    for(int i=1;i<=n;i++)if(f[i][i+n-1]==ans)printf("%d ",i);
    return 0;
}