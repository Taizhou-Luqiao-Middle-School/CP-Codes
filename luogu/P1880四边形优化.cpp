// Date: 2021-10-18 07:44:35
// Problem: P1880 [NOI1995] 石子合并
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1880
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Stauts: ACcept
// Author: Guan Yongjie

#define DEBUG 1 //调试开关
#include <bits/stdc++.h>
using namespace std;
int a[2005], sum[2005];
int fsmallest[2005][2005], fbiggest[2005][2005], ssmallest[2005][2005];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[i + n] = a[i];
        sum[i] = sum[i - 1] + a[i];
        ssmallest[i][i] = i;
    }
    for (int i = 1 + n; i <= (n << 1); i++)
    {
        sum[i] = sum[i - 1] + a[i];
        ssmallest[i][i] = i;
    }
    for (int i = (n << 1) - 1; i; i--)
        for (int j = i + 1; j <= (n << 1); j++)
        {
            int jc = 0, tmp = 0x3f3f3f3f;
            fbiggest[i][j] = max(fbiggest[i][j - 1], fbiggest[i + 1][j]) + sum[j] - sum[i - 1];
            /*注意这句，
              求最大值不能用四边形不等式，
              因为最大值不满足单调性，
              但最大值有一个性质，
              即总是在两个端点的最大者中取到。
            */
            for (int k = ssmallest[i][j - 1]; k <= ssmallest[i + 1][j]; k++)
            {
                int tt = fsmallest[i][k] + fsmallest[k + 1][j] + (sum[j] - sum[i - 1]);
                if (tt < tmp)
                {
                    tmp = tt;
                    jc = k;
                }
            }
            ssmallest[i][j] = jc;
            fsmallest[i][j] = tmp;
        }
    int ama = 0, ami = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        ama = max(ama, fbiggest[i][i + n - 1]);
        ami = min(ami, fsmallest[i][i + n - 1]);
    }
    printf("%d\n%d", ami, ama);

    return 0;
}
/*
我们是令k=y时dp[i][j-1]取得最小值
那么dp[i][j-1] (k=x)一定大于等于dp[i][j-1] (k=y)
所以左式大于零，所以右式也大于零，所以对于dp[i][j-1]可以取到最优值的y
所有小于它的值，对于dp[i][j]来说，都没有y优，所以最优决策一定不是小于y的
如果令s[i][j]表示dp[i][j]取得最优值的时候的k值，那么一定有s[i][j-1]<=s[i][j] 
尤其要注意for的顺序
因为我们在推dp[i][j]的时候要用s[i][j-1]和s[i+1][j]
所以i一定是倒序的
这样才能在求dp[i][j]的时候调用dp[i+1][j]的最优决策s[i+1][j]
而j一定是顺序的
这样才能在求dp[i][j]的时候调用dp[i][j-1]的最优决策s[i][j-1]

求最大值不能用四边形不等式，
因为最大值不满足单调性，
但最大值有一个性质，
即总是在两个端点的最大者中取到。
*/