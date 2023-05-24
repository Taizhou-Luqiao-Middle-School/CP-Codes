#include <bits/stdc++.h>
using namespace std;

signed main(){
    int a[3];
    int n;
    cin>>n;
    int i=0;
    while (n){
        a[i] = n%10;
        i++;
        n/=10;
    }
    sort(a,a+3);
    int r=0;
    for (int p=2;p>=0;p--){
        r= r*10 + a[p];
    }
    cout<<r;
    return 0;
}

