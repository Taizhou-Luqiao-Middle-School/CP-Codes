//Author: CodeBoy

#include<iostream>
using namespace std;
int a[100005];

int main(){
    int n,m;
    cin>>n>>m;
    a[0] = 0;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        a[i]=a[i-1]+t;
    }
    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;
        cout<<a[r]-a[l-1]<<endl;
    }
    return 0;
}