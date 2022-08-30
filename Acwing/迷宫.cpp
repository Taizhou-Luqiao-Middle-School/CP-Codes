//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Re register
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))
using namespace std;
typedef long long ll;
const int N = 105;
char a[N][N];
int n;
bool st[N][N];
const int dx[] = {0, -1, 1, 0};
const int dy[] = {1, 0, 0, -1};
int xa, ya, xb, yb;
bool dfs(int x, int y){
    if(x==xb&&y==yb){
        return true;
    }
    st[x][y] = 1;
    for(int i=0;i<4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx>=n||ny>=n||nx<0||ny<0||a[nx][ny]=='#') continue;
        if(st[nx][ny]) continue;
        
        if(dfs(nx, ny)) return true;
    }
    return false;
}

int main(){
    int k;
    scanf("%d", &k);

    while(k--){
        memset(st, false, sizeof st);
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%s", a[i]);
        }
        
        scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
        if(a[xa][ya] == '#' || a[xb][yb] == '#')
        {
            puts("NO");
            continue;
        }
        if(dfs(xa, ya))puts("YES");
        else puts("NO");
    }
    return 0;
}

/*
.....
###.#
..#..
###..
...#.
0 0 4 0
*/