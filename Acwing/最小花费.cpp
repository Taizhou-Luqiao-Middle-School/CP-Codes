#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2005;
const int M = 100005;

int n, m, S, T;
double a[N][N], dist[N];
bool st[N];
void dijkstra(){
    dist[S] = 1;
    for(int i=1;i<=n;i++){
        int t = -1;
        for(int j=1;j<=n;j++)
            if(!st[j] && (t==-1||dist[t]<dist[j]))
                t = j;
        st[t] = 1;
        for(int j=1;j<=n;j++)
            dist[j] = max(dist[j], dist[t] * a[j][t]);
        }
    
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x, y, z;
        cin>>x>>y>>z;
        a[y][x] = a[x][y] = max(a[x][y], (100.0 - z) / 100);
    }
    cin>>S>>T;
    double ans;
    dijkstra();
    printf("%.8lf\n", 100/dist[T]);
    return 0;
}