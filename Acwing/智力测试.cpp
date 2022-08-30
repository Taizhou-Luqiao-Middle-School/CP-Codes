#include <bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
    int n;
    cin>>n;
    int i=1;
    a[0]=0;
    for(i;i<=10005;i++){
        a[i]=i*(i+1)/2.0 + a[i-1];
        // cout<<a[i]<<endl;
        if(a[i]>n) break;
    }
    cout<<i-1<<endl;
    return 0;
}