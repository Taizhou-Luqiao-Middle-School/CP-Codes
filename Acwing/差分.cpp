//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N =100005;
int a[N];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int t,bt=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t);
        a[i]=t-bt;
        bt=t;
    }
    for(int i=0;i<m;i++){
        int l,r,c;
        scanf("%d%d%d",&l,&r,&c);
        a[l]+=c;a[r+1]-=c;
    }
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
        printf("%d ",a[i]);
    }
    return 0;
}