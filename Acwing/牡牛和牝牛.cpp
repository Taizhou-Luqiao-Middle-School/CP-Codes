#include <iostream>
#define ll long long
using namespace std;
const int mod = 5000011;
ll f[100005];
int main(){
    ll n, k;
    
    cin>>n>>k;
    for(int i=1;i<=k+1;i++)
        f[i] = 1  + i;
    for(int i=k+2;i<=n;i++){
        f[i] = (f[i-1] + f[i-k-1]) % mod;
    }
    // for(int i=0;i<=n;i++)
    //     cout<<f[i]<<endl;
    cout<<f[n]<<endl;
    return 0;
}