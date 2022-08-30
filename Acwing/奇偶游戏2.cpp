//扩展域并查集
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int N = 20010;

int n, m;
int p[N*2];
unordered_map<int, int> S;
int get(int x)
{
    if (S.count(x) == 0)
        S[x] = ++n;
    return S[x];
}
int find(int x)
{
    if (p[x] != x){p[x]= find(p[x]);}
    return p[x];
}
int main()
{
    cin >> n >> m;
    n = 0;
    for (int i = 0; i < N*2; i++)
        p[i] = i;
    int res = m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        string type;
        cin >> a >> b >> type;
        a = get(a - 1), b = get(b);
        if (type == "even")
        {
            if (find(a + N) == find(b))
            {
                res = i - 1;
                break;
            }
            p[find(a)] = find(b);
            p[find(a + N)] = find(b + N);
        }
        else
        {
            if (find(a) == find(b))
            {
                res = i - 1;
                break;
            }

            p[find(a + N)] = find(b);
            p[find(a)] = find(b + N);
        }
    }
    cout << res << endl;
    return 0;
}