//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[1005],v[1005],w[1005];
int main(){
    int t,m;
    cin>>t>>m;
    for(int i=0;i<m;i++){
        cin>>v[i]>>w[i];
    }
    for(int i=0;i<m;i++){
        for(int j=t;j>=v[i];j--){
            f[j] = max(f[j-v[i]] +w[i], f[j]);
        }
    }
    cout<<f[t]<<endl;
    return 0;
}