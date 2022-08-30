#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n,a[N],g[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int tt=1;
    bool flag =false;
    memset(g,0,sizeof g);
    for(int i=1;i<=n;i++){

        if(a[i]==0&&flag!=true){
            for(int j=1;j<i;j++){
                g[j]=i-j;
            }
        }
        if(a[i]==0) tt=1,flag=true;
        if(a[i+1]!=0&&flag==true) g[i+1] = tt;
        tt++;
    }
    // for(int i=1;i<=n;i++){
    //     printf("%d ",g[i]);
    // }
    // printf("\n");
    tt=1;
    flag =false;
    for(int i=n;i>=1;i--){
        if(a[i]==0) tt=1,flag=true;
        if(a[i-1]!=0&&g[i-1]!=0&&flag==true) g[i-1] = min(tt,g[i-1]);
        tt++;
    }
    for(int i=1;i<=n;i++){
        printf("%d ",g[i]);
    }
    return 0;
}