#include <iostream>
using namespace std;
int w[] = {10, 20, 50, 100};
int n, f[1005];
int main(){
    cin>>n;
    f[0] = 1;
    for(int i=0;i<4;i++){
        for(int j=w[i];j<=n;j++){
            f[j] += f[j-w[i]];
        }
    }

    cout<<f[n]<<endl;
    return 0;
}