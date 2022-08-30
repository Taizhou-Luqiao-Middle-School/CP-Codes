//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a[10],st[10],cnt=0;
void dfs(int d){
    if(d==n){
        for(int i=0;i<n;i++){
            cout<<a[i]<<' ';
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!st[i])
        {
            st[i]=1;
            a[cnt++] = i;
            dfs(d+1);
            st[i]=0;
            a[cnt--] = 0;
        }
        
    }
}
int main(){
    cin>>n;
    dfs(0);
    return 0;
}