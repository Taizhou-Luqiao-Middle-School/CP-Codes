//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 100010, mod =1e9+7;
int fact[N],invfact[N];
ll qpow(ll a,int b,int p){ //因为a会被算平方所以要用ll否则可能会溢出
    ll res=1;
    while(b){
        if(b&1) res = res * a % p;
        b>>=1;
        a = a*a % p;
    }
    return res;
}
//或者这样写
// int qpow(int a, int k, int p)
// {
//     int res = 1;
//     while (k)
//     {
//         if (k & 1) res = (ll)res * a % p;
//         a = (ll)a * a % p;
//         k >>= 1;
//     }
//     return res;
// }


int main(){
    fact[0] = invfact[0] = 1;
    for(int i=1;i<N;i++){
        fact[i] = (ll)fact[i-1] * i % mod;
        invfact[i] = (ll)invfact[i-1] * qpow(i,mod - 2 ,mod) % mod;
    }
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",(ll)fact[a]%mod * invfact[b]%mod * invfact[a-b]%mod);
    }
    return 0;
}