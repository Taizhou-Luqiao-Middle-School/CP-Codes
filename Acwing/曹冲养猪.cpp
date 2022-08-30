#include <iostream>
using namespace std;
typedef long long ll;
// int exgcd(ll a, ll b, ll &x, ll&y){
//     if(!b){
//         x = 1, y= 0;
//         return a;
//     }
//     ll d = exgcd(a, a%b, y, x);
//     y -= a/b *x;
//     return d;
// }
// int main(){
//     int n;
//     cin>>n;

//     ll x = 0, m1, a1;
//     cin>>m1>>a1;
//     for(int i=0;i<n-1;i++){
//         ll m2, a2;
//         cin>>m2>>a2;
//         ll k1, k2;
//         ll d = exgcd(m1, m2, k1, k2);
//         if((a2-a1)%d){
//             x = -1;
//             break;

//             k1 *= (a2 -a1)/d;
//             k1 = 
//         }
//     }
//     return 0;
// }
const int N = 15;

int a[N], b[N];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    ll ans = b[0], m = a[0];
    for(int i=1;i<n;i++){
        while(ans%a[i]!=b[i]){
            ans += m;
        }
        m*=a[i];
    }
    cout<<ans<<endl;
    return 0;
}