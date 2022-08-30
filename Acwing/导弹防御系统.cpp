#include <iostream>
using namespace std;
const int N = 55;

int n;
int q[N];
int up[N], down[N];
int ans;
void dfs(int u, int su, int sd)
{
    if (su + sd >= ans)
        return;
    if (u == n)
    {
        ans = su + sd;
        return;
    }

    int k = 0;
    while (k < su && up[k] >= q[u])
        k++;
    int t = up[k];
    up[k] = q[u];
    if (k < su)
        dfs(u + 1, su, sd);
    else
        dfs(u + 1, su + 1, sd);
    up[k] = t;

    k = 0;
    while (k < sd && down[k] <= q[u])
        k++;
    t = down[k];
    down[k] = q[u];
    if (k < sd)
        dfs(u + 1, su, sd);
    else
        dfs(u + 1, su, sd + 1);
    down[k] = t;
}
int main()
{
    while (cin >> n, n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> q[i];
        }
        ans = n;
        dfs(0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}
