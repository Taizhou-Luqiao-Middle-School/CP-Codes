#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long a[1001][1001];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    long long ans1=0,ans2=0;
    for(int i=1;i<=n;i++){
        ans1+=a[i][i];
    }
    int j=1;
    for(int i=n;i>=1;i--){
        ans2+=a[i][j];
        j++;
    }
    cout<<ans1<<endl<<ans2;
}
