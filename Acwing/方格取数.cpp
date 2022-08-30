#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 15;

int w[N][N],f[N*2][N][N];

int main(){
    int n,r,c,tmp;
    cin>>n;
    memset(w,0,sizeof w);
    memset(f,0,sizeof f);
    while(1){
        cin>>r>>c>>tmp;
        if(!r&&!c&&!tmp) break;
        w[r][c] = tmp;
    }
    for(int k=2;k<=n*2;k++){
        for(int i1=1;i1<=n;i1++){
            for(int i2=1;i2<=n;i2++){
                int j1= k -i1,j2=k-i2;
                if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n)
                {
                    int t = w[i1][j1];
                    if (i1 != i2) t += w[i2][j2];
                    int &x = f[k][i1][i2];
                    x = max(x, f[k - 1][i1 - 1][i2 - 1] + t);
                    x = max(x, f[k - 1][i1 - 1][i2] + t);
                    x = max(x, f[k - 1][i1][i2 - 1] + t);
                    x = max(x, f[k - 1][i1][i2] + t);
                }
            }
        }
    }
    cout<<f[n + n][n][n]<<endl;
    return 0;

}