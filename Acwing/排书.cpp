#include <iostream>
#include <cstring>
using namespace std;

const int N = 15;
int q[N], w[6][N];
int n;

int f()
{
    int res = 0;
    for (int i = 0; i + 1 < n; i++)
    {
        if (q[i + 1] != q[i] + 1)
            res++;
    }
    return (res + 2) / 3;
}

bool check()
{
    for (int i = 0; i < n; i++)
    {
        if (q[i] != i + 1)
        {
            return false;
        }
    }
    return true;
}

bool dfs(int depth, int max_depth)
{
    if (depth + f() > max_depth)
        return false;
    if (check())
        return true;

    for (int l = 0; l < n; l++)
    {
        for (int r = l; r < n; r++)
        {
            for (int k = r + 1; k < n; k++)
            {
                memcpy(w[depth], q, sizeof q);
                int x, y;
                for (x = r + 1, y = l; x <= k; x++, y++)
                {
                    q[y] = w[depth][x];
                }
                for (x = l; x <= r; x++, y++)
                {
                    q[y] = w[depth][x];
                }
                if (dfs(depth + 1, max_depth))
                    return true;
                memcpy(q, w[depth], sizeof q);
            }
        }
    }

    return false;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {

        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> q[i];
        }

        int depth = 0;
        while (depth < 5 && !dfs(0, depth))
            depth++;
        if (depth >= 5)
            puts("5 or more");
        else
            printf("%d\n", depth);
    }

    return 0;
}