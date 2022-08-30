#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m;
int w[N][N];
int f[N][N];

int main()
{
    int T;
    cin>>T;
    while (T -- )
    {
        cin>>n>>m;
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= m; j ++ )
                cin>>w[i][j];

        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= m; j ++ )
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + w[i][j];

        cout<<f[n][m]<<endl;
    }

    return 0;
}
