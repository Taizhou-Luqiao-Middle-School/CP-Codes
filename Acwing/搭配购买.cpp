#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 10050;

int n,m,vol;
int v[N],w[N];
int p[N];
int f[N];
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int main(){
    cin>>n>>m>>vol;

    for(int i=1;i<=n;i++) p[i]= i ;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];

    while(m--){
        int a,b;
        cin>>a>>b;
        int pa = find(a), pb = find(b);
        if(pa!=pb){
            v[pb]+=v[pa];
            w[pb]+=w[pa];
            p[pa]=p[pb];
        }
    }
    for(int i=1;i<=n;i++){
        if(p[i]==i){
            for(int j=vol;j>=v[i];j--){
                f[j]=max(f[j],f[j-v[i]]+w[i]);
            }
        }
    }
    cout<<f[vol]<<endl;
    return 0;
}