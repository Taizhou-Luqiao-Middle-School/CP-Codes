//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2010,mod = 1e9+7;
int C[N][N];
void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            if(j==0) C[i][j] = 1;
            else{
                C[i][j] = (C[i-1][j-1]+C[i-1][j]) % mod;
            }
        }
    }
}
int main(){
    init();
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        cout<<C[a][b]<<endl;
    }
    return 0;
}