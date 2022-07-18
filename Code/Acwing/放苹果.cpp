#include <iostream>
using namespace std;
long long calc(int n, int m){
    long long res = 0;
    if(n<=1) return 1;
    if(m<=1) return 1;
    if(m>n) return calc(n,n);
    return calc(n-m, m) + calc(n, m-1);
}
int main(){
    int n,m;
    while(cin>>n>>m){
        long long ans = calc(n, m);
        cout<<ans<<endl;
    }
    
    return 0;
}