#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1000005, mod =100003;
vector<int> g[N];
int dep[N], cnt[N];
bool vis[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i=0;i<m;i++){
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    queue<int> q;
    dep[1] = 0;vis[1]=1;q.push(1);cnt[1] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<g[x].size();i++){
            int t = g[x][i];
            if(!vis[t]){
                vis[t] = 1;
                dep[t] = dep[x] + 1;
                q.push(t);
            }
            if(dep[t] == dep[x]+1){
                cnt[t] = (cnt[t]+cnt[x])%mod;
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<cnt[i]<<endl;
    return 0;
}