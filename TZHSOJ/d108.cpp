#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,n,m[1001];
    cin>>n;
    for(int i=0;i<n;i++){cin>>m[i];}
    sort(m,m+n);
    cin>>a;
    for(int i=n;i>=0;i--){
        if(m[i]==a){
        cout<<n-i;
        return 0;}
    }
}
