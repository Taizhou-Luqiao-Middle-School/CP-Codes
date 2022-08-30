//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
int n,m;
int a[105][105],vis[105][105];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int bfs()
{
    queue<PII> q;

    memset(vis, -1, sizeof vis);
    vis[0][0] = 0;
    q.push({0, 0});
    while (q.size())
    {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 4; i ++ )
        {
            int x = t.first + dx[i], y = t.second + dy[i];

            if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 0 && vis[x][y] == -1)
            {
                vis[x][y] = vis[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
    }

    return vis[n - 1][m - 1];
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    cout<<bfs()<<endl;
    return 0;
}