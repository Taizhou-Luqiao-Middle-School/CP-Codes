// Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Re register
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))
using namespace std;
typedef long long ll;

const int N = 22, M = 80;

int n, m, K;
int f[N][M];

int main()
{
    cin >> n >> m >> K;

    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;

    while (K--)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        for (int i = n; i >= 0; i--)
            for (int j = m; j >= 0; j--)
                f[i][j] = min(f[i][j], f[max(0, i - v1)][max(0, j - v2)] + w);
    }

    cout << f[n][m] << endl;

    return 0;
}