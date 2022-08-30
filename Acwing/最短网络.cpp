//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=110;
int n;
int w[N][N];
int dist[N];//dist存的是当前连通块和外面的每个点直接相连的边的长度的最小值
bool st[N];//当前这个点是否在连通块内

int prim()
{
    int res = 0;
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < n; i ++ )//循环n次 每次循环连通块通过最小边加入一个点
    {
        //第2及2次以上的循环 最小边所连的点 也是初始化为-1
        int t = -1;
        for (int j = 1; j <= n; j ++ )
            //j不在连通块内 如果当前还没设置连通块 与外接的最小边(t==-1) || 与j的距离比当前点最小距离的点t还小
            if (!st[j] && (t == -1 || dist[t] > dist[j]))//因为dist[1] = 0 则1肯定作为第一个点加入连通块
                t = j;
        res += dist[t];
        st[t] = true;

        //dist[j] 通过min(dist[j], w[t][j])维护连通块到达每个点的最小距离
        // 假设加进连通块的顺序为 1→2→3
        //t为连通块现在刚加进来的最小点 
        // 在只加进1的时候 dist[j]为所有点到1的距离 dist[j] = w[1][j]
        // t更新为2的时候 dist[j]= min(dist[j], w[t][j])
        //                 则更新为min(w[1][j],w[2][j]);
        // t更新为3的时候 dist[j]= min(dist[j], w[t][j])
        //                 则更新为min(w[1][j],w[2][j],w[3][j]);
        for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], w[t][j]);
    }
    return res;
}
int main()
{
    cin >> n;
    //输入邻接矩阵
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            cin >> w[i][j];

    cout << prim() << endl;

    return 0;

}
