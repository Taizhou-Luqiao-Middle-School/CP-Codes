#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 100003;
ll qpow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1) res = (ll) res * a % mod;
        b>>= 1;
        a = (ll) a * a % mod;
    }

    return res;
}


int main(){
    ll n,m;
    cin>>m>>n;
    cout<<(qpow(m, n) - (ll)m * qpow(m - 1, n - 1) % mod + mod) % mod <<endl;
    return 0;
}