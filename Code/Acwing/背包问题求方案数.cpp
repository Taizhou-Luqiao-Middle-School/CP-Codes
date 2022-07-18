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
const int MAXN = 1005, mod = 1e9+7;
int f[MAXN], v[MAXN], w[MAXN], cnt[MAXN];
int main(){
    int N, V;
    scanf("%d%d", &N, &V);
    for(int i=0;i<N;i++){
        scanf("%d%d", &v[i], &w[i]);
    }
    for(int i = 0; i <= V; i ++)  cnt[i] = 1;
    for(int i=0;i<N;i++){
        for(int j=V;j>=v[i];j--){
            if(f[j-v[i]]+w[i] > f[j]) f[j] = f[j-v[i]]+w[i], cnt[j] = cnt[j-v[i]];
            else if(f[j-v[i]]+w[i] == f[j]) cnt[j] = (cnt[j] + cnt[j - v[i]])%mod;
        }
    }
    printf("%d\n", cnt[V]);
    return 0;
}