#include <iostream>
#define int long long
using namespace std;
const int N = 100005, M = 10000005;
int w[N], v[N], f[M];
signed main(){
    int t, m;
    cin>>t>>m;
    for(int i=0;i<m;i++)
        cin>>v[i]>>w[i];
    for(int i=0;i<m;i++){
        for(int j=v[i];j<=t;j++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    }
    cout<<f[t]<<endl;
    return 0;
}