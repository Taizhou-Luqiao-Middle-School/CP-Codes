//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5+5;
int a[N], f[2][N];
int main(){
    int T,n;
    cin>>T;
    while(T--){
        memset(f, 0 ,sizeof f);
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
        }
        // for(int i=1;i<=n;i++){
        //     cout<<a[i]<<' ';
        // }
        // cout<<endl;
        for(int i=1;i<=n;i++){
            for(int j=0;j<2;j++){
                // cout<<j<<endl;
                if(j==0) f[j][i] = max(f[j][i], max(f[0][i-1],f[1][i-1]));
                else {
                    f[j][i] = max(f[j][i], f[0][i-1]+a[i]);
                }
            }
        }
        // for(int i=1;i<=n;i++){
        //     for(int j=0;j<2;j++){
        //         cout<<i<<' '<<j<<' '<<f[j][i]<<endl;
        //     }
        // }
        cout<<max(f[0][n],f[1][n])<<endl;
    }
    
    return 0;
}