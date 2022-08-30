#include <iostream>
#define re register
using namespace std;
const int N = 300;
int a[N], path[N], f[N], pos;
bool c[N][N];
void print(int x)
{
    if (path[x])
        print(path[x]);
    cout << x << ' ';
}
int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (re int i = 1; i <= n - 1; i++)
    {
        for (re int j = i + 1; j <= n; j++)
        {
            bool tmp;
            cin >> tmp;
            c[i][j] = c[j][i] = tmp;
        }
    }
    f[1] = a[1];
    for (re int i = 2; i <= n; i++)
    {
        f[i] = a[i];
        for (re int j = i - 1; j > 0; j--)
        {
            if (c[j][i] && f[i] < f[j] + a[i])
            {
                f[i] = f[j] + a[i];
                path[i] = j;
            }
        }
        if (ans < f[i])
        {
            ans = f[i];
            pos = i;
        }
    }
    print(pos);
    cout << endl
         << ans << endl;
    return 0;
}