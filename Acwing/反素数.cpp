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
const ll N = 2*10e9 + 5;
int maxd, num, n;
const int primes[9]={2,3,5,7,11,13,17,19,23};

void dfs(int u, int last, int p, int s){
    if(s > maxd || s == maxd && p < num){
        maxd = s;
        num = p;
    }
    if(u == 9) return;

    for(int i=1;i<=last;i++){
        if((ll)p * primes[u] > n) break;
        p *= primes[u];
        dfs(u+1, i, p, s*(i+1));
    }
}
int main(){
    cin>>n;

    dfs(0, 30, 1, 1);

    cout<<num<<endl;
    return 0;
}