//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1005;

int w[N],v[N];
int f[N];

int main(){
    int num,vol;
    cin>>num>>vol;
    for(int i=0;i<num;i++){
        cin>>v[i]>>w[i];
    }
    for(int i=0;i<num;i++){
        for(int j=vol;j>=v[i];j--)
        {
            f[j] = max(f[j],f[j-v[i]]+w[i]); //j-v[j] 一定小于 j 所以其实是用上一层的数据
        }
    }
    cout<<f[vol]<<endl;
    return 0;
}