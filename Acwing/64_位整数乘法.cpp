#include <iostream>
using namespace std;
typedef long long ll;
ll qquad(ll a,ll b,ll p){
    ll res = 0;
    while(b){
        if(b&1) res = (res+a)%p;
        a = (a+a)%p;
        b>>=1;
    }
    return res;
}
int main(){
    ll a,b,p;
    cin>>a>>b>>p;
    cout<<qquad(a,b,p)<<endl;
    return 0;
}