//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define x first
#define y second
using namespace std;
const int N = 1010;
typedef pair<int,int> PII;
int n;
int h[N][N];
bool st[N][N];
PII q[N*N];

void bfs(int sx, int sy, bool& has_higher, bool &has_lower){
    int hh=0, tt =0;
    q[0] = {sx, sy};
    st[sx][sy] = 1;
    while(hh<=tt){
        PII t = q[hh++];
        for(int i=t.x-1; i<=t.x+1;i++){
            for(int j = t.y-1; j<=t.y+1;j++){
                if (i == t.x && j == t.y) continue;
                if(i<0||i>=n||j<0||j>=n) continue;
                if(h[i][j] != h[t.x][t.y]){
                    if(h[i][j] > h[t.x][t.y]) has_higher = true;
                    else has_lower = true;
                }
                else if(!st[i][j]){
                    q[++tt] = {i, j};
                    st[i][j] =true;
                }

            }
        }
    }
    return;
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &h[i][j]);
        }
    }
    int peak = 0, valley = 0; 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!st[i][j]){
                bool has_higher = false, has_lower = false;
                bfs(i, j, has_higher, has_lower);
                if(!has_higher) peak++;
                if(!has_lower) valley++;
            }

        }
    }
    printf("%d %d\n", peak, valley);
    return 0;
}