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
const int N = 1e5 + 10, M = 110;

int n, k;
int w[N];
int f[N][M][2];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i) cin >> w[i];

    memset(f, -0x3f, sizeof f);
    f[0][0][0] = 0; //初始状态f[0][0][0]

    for (int i = 1; i <= n; ++ i)
    {
        for (int j = 0; j <= k; ++ j)
        {
            f[i][j][0] = f[i - 1][j][0];
            if (j) f[i][j][0] = max(f[i][j][0], f[i - 1][j - 1][1] + w[i]);
            f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j][0] - w[i]);
        }
    }

    int res = 0;
    for (int j = 0; j <= k; ++ j) res = max(res, f[n][j][0]); //目标状态f[n][j][0]

    cout << res << endl;

    return 0;
}