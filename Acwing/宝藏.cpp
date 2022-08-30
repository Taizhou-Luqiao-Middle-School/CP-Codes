// Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 12, M = 1 << 12, INF = 0x3f3f3f3f;
int n, m;
int d[N][N];
int f[M][N], g[M], id[M]; // f[i][j]:集合i扩展深度j，g[i]:集合i的扩展集合
                          // id[i]:单个1的位置

int main()
{
    scanf("%d%d", &n, &m);

    memset(d, 0x3f, sizeof d);
    for (int i = 0; i < n; i++)
        d[i][i] = 0, id[1 << i] = i;

    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--; //从0编号
        d[a][b] = d[b][a] = min(d[a][b], c);
    }

    for (int i = 1; i < 1 << n; i++)
        for (int x = i, j = x & -x; j; x -= j, j = x & -x)
        { //采用lowbit技术
            for (int k = 0; k < n; k++)
                if (d[id[j]][k] != INF)
                    g[i] |= 1 << k; //子集i连接的集合，即子集i的扩展集合
        }

    memset(f, 0x3f, sizeof f);
    for (int i = 0; i < n; i++)
        f[1 << i][0] = 0; //每个节点单独不需代价

    for (int i = 1; i < 1 << n; i++) //计算i时，i的子集已经全部计算出来了
        for (int j = (i - 1); j; j = (j - 1) & i)
        { //枚举i的真子集j
            if ((g[j] & i) != i)
                continue;  //如果i不是j的扩展集合的子集，跳过
            int x = i ^ j; //相当于集合i-集合j，差集i-j
            int cost = 0;
            for (int k = x & -x; k; x -= k, k = x & -x)
            { //采用lowbit技术
                int t = INF, y = j;
                for (int u = y & -y; u; y -= u, u = y & -y)
                    t = min(t, d[id[k]][id[u]]); //集合j扩展到i-j的某个点的最小代价
                cost += t;                       //累积集合j扩展到i-j的代价，扩展完，变成了i
            }
            for (int k = 1; k < n; k++)                         //从j扩展到i,但深度不知是多少，所以全部计算一下
                f[i][k] = min(f[i][k], f[j][k - 1] + cost * k); //最终小的就是那个结果
        }

    int res = INF;
    for (int i = 0; i < n; i++)
        res = min(res, f[(1 << n) - 1][i]); //取小的结果

    printf("%d\n", res);
    return 0;
}
