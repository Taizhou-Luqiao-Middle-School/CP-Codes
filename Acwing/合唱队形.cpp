#include <iostream>
using namespace std;
const int N  = 115;
int a[N], f[N], g[N];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        f[i] = 1;
        for(int j=1;j<i;j++){
            if(a[i]>a[j]){
                f[i] = max(f[i],f[j] + 1);
            }
        }
    }

    for(int i=n;i;i--){
        g[i] = 1;
        for(int j=n;j>i;j--){
            if(a[i]>a[j]){
                g[i] = max(g[i],g[j] + 1);
            }
        }
    }

    int res = 0;
    for(int i=1;i<=n;i++) res = max(res, f[i]+g[i]-1);
    cout<< n - res <<endl;
    return 0;
}