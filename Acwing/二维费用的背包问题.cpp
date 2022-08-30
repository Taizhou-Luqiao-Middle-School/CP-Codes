//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Re register
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))
using namespace std;
typedef long long ll;
const int N = 1005;
int v[N], m[N], w[N];
int f[N][N];
int main(){
    int n, V, M;
    scanf("%d%d%d", &n, &V, &M);
    for(int i=0;i<n;i++){
        scanf("%d%d%d", &v[i], &m[i], &w[i]);
    }

    for(int i=0;i<n;i++){
        for(int j=V;j>=v[i];j--){
            for(int k=M;k>=m[i];k--){
                f[j][k] = max(f[j-v[i]][k-m[i]] + w[i], f[j][k]);
            }
        }
    }
    cout<<f[V][M]<<endl;
    return 0;
}