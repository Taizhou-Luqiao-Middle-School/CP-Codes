//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define Re register
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
vector<int> g[N];
int deg[N], st[N];
bool flag;

void dfs(int u){
    
    st[u] = 1;
    for(auto x : g[u]){
        if(!st[x]){
            if(deg[x]!=2) flag = 1;
            dfs(x);
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a] ++, deg[b] ++;
    }

    int res = 0;

    for(int i=1;i<=n;i++){
        if(st[i]) continue;
        if(deg[i]!=2) continue;
        flag = 0;
        dfs(i);
        if(flag) continue;
        res ++;
    }
    cout<<res<<endl;
    return 0;
}