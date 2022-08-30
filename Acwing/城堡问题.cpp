//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int,int> PII;
const int N = 55, M = N*N;

int n,m;
int g[N][N];
PII q[M];
bool st[N][N];

int bfs(int sx, int sy){
    int dx[4] = {0,-1,0,1}, dy[4] = {-1,0,1,0};
    int hh=0,tt = 0;
    int area = 0;

    q[0] = {sx, sy};
    st[sx][sy] = 1;

    while(hh<=tt){
        PII t = q[hh++];
        area ++;
        for(int i=0;i<4;i++){
            int a = t.x + dx[i], b = t.y+dy[i];
            if(a<0||a>=n||b<0||b>=m) continue;
            if(st[a][b]) continue;
            if(g[t.x][t.y] >> i & 1) continue;

            q[++tt] = {a,b};
            st[a][b] = true;
        }
    }
    return area;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }
    int cnt = 0;
    int area = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!st[i][j]){
                area = max(area, bfs(i,j));
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    cout<<area<<endl;
    return 0;
}