#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 20005;

int f[N], w[40];
int main(){
    int V,n;
    cin>>V>>n;
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        for(int j=V;j>=w[i];j--){
            f[j]=max(f[j],f[j-w[i]]+w[i]);
        }
    }
    cout<<V-f[V]<<endl;
    return 0;
}

/*
简单的01背包问题
*/