#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 200907;

ll qpow(int a, int b){
    ll res = 1;
    while(b){
        if(b&1) res = (ll)res * a % mod;
        b >>= 1;
        a = (ll)a * a % mod;
    }
    return res;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int a,b,c,k;
        cin>>a>>b>>c;
        cin>>k;
        if(b-a==c-b){
            cout<<(a + (b-a) * (ll)(k-1)) % mod <<endl;
        } else {
            cout<<(ll)a * qpow(b/a, k-1) % mod <<endl;
        }
    }
    return 0;
}