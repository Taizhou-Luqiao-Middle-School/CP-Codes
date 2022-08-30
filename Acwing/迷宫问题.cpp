// Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;

const int N = 1005;
int m[N][N], st[N][N];
PII path[N][N];
void bfs(int n)
{
    queue<PII> q;
    q.push({n - 1, n - 1});
    st[n - 1][n - 1] = 1;
    int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = dx[i] + t.x, y = dy[i] + t.y;
            if(
                m[x][y]==1||
                st[x][y]==1||
                (x < 0 || x >= n || y < 0 || y >= n)
            ){
                continue;
            }
            q.push({x, y});
            st[x][y] = 1;
            path[x][y] = t;
        }
    }
}
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
    bfs(n);
    PII end = {0, 0};

    cout << 0 << ' ' << 0 << endl;

    while (end.x != n - 1 || end.y != n - 1)
    {
        printf("%d %d\n", path[end.x][end.y].x, path[end.x][end.y].y);
        int x = end.x, y = end.y;
        end.x = path[x][y].x, end.y = path[x][y].y;
    }
    return 0;
}