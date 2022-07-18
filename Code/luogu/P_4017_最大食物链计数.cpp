#include <iostream>
#define Re register
using namespace std;
const int mod = 80112002, N = 5005;
int in[N], out[N], mem[N], head[100 * N], cnt;
struct e{
    int to, next;
} edge[N*100];

inline void add(int x, int y){
    edge[++cnt].to = y;
    edge[cnt].next = head[x];
    head[x] = cnt;
}

int dfs(int st){
    if(!out[st]) return 1;  //找到终点
    if(mem[st]) return mem[st];
    int res = 0;
    for(Re int i=head[st];i;i=edge[i].next)
        res = (res + dfs(edge[i].to)) % mod;
    mem[st] = res % mod;
    return mem[st];
}
int main(){
    int n,m;
    cin>>n>>m;
    for(Re int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        in[b]++, out[a]++;
        add(a, b);
    }
    int ans = 0;
    for(Re int i=1;i<=n;i++){
        if(!in[i]) ans = (ans + dfs(i)) % mod;
    }
    cout<<ans<<endl;
    return 0;
}