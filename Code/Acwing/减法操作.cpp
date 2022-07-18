//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Re register
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))
using namespace std;
typedef long long ll;
const ll N = 1e5+5, M = 1e5+5;

ll get_minimum_factor(ll n){
    for(int i=2;i<=n/i;i++){
        if(n % i == 0) return i;
    }
    return -1;
}

int main(void){
    ll n;
    cin>>n;
    ll ans = 0;

    ll factor = get_minimum_factor(n);

    ans = (n-factor)/2 + 1;

    cout<<ans<<endl;
    return 0;
}