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
int cnt, n, k;
void dfs(int d, int s, int l){
    if(d == k){
        if(s == n) cnt ++;
        return;
    }
    for(int i=l;s+i*(k-d)<=n;i++){
        dfs(d + 1, s + i, i);
    }
}

int main(){
    cin>>n>>k;
    dfs(0, 0, 1);
    cout<<cnt<<endl;
    return 0;
}