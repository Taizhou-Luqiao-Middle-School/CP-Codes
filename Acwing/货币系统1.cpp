#include <iostream>
#define int long long
using namespace std;
int w[20], f[3050];
signed main(){
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    f[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=w[i];j<=m;j++){
            f[j] += f[j-w[i]];
        }
    }

    cout<<f[m]<<endl;
    return 0;
}