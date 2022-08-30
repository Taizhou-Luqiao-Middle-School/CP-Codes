//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 20005;
int f[N],v[N];
int main(){
    int V,n;
    cin>>V>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        for(int j = V;j>=v[i];j--){
            f[j] = max(f[j],f[j-v[i]]+v[i]);
        }
    }
    cout<<V - f[V]<<endl;
    return 0;
}