#include <iostream>
using namespace std;
const int N = 1005;
int a[N][N], b[N][N];
void modify(int x1, int y1, int x2, int y2, int c){
    b[x1][y1] += c;
    b[x2+1][y1] -= c;
    b[x1][y2+1] -=c;
    b[x2+1][y2+1] += c;
}
void print(int n, int m){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<b[i][j]<<' ';

        }
                cout<<endl;

    }
            cout<<endl;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
            cout<<b[i][j]<<' ';
        }
        cout<<endl;
    }
}
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            modify(i,j,i,j,a[i][j]);
        }
    }
    for(int i=0;i<q;i++){
        int x1,y1,x2,y2,c;
        cin>>x1>>y1>>x2>>y2>>c;
        modify(x1, y1, x2, y2, c);
    }
    print(n, m);
    return 0;
}