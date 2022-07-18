#include <iostream>
using namespace std;
const int N = 100, M  = 10005;
int w[N],f[M];
int main(){
    int n,m;
    cin>>n>>m;
    f[0] = 1;
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        for(int j=m;j>=w[i];j--){
            f[j] += f[j-w[i]];
        }
    }
    cout<<f[m]<<endl;
    return 0;
}