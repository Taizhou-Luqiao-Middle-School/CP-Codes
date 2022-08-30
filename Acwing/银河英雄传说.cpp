#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 30050;

int s[N], p[N], d[N];
int find(int x)
{
    if (p[x] != x)
    {
        int root = find(p[x]);
        d[x] += d[p[x]];
        p[x] = root;
    }
    return p[x];
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= N; i++)
        p[i] = i, s[i] = 1;
    while (T--)
    {
        char O[2];
        scanf("%s", &O);
        if (O[0] == 'M')
        {
            int a, b;
            scanf("%d%d", &a, &b);
            int pa = find(a), pb = find(b);
            d[pa] = s[pb];
            s[pb] += s[pa];
            p[pa] = pb;
        }
        if (O[0] == 'C')
        {
            int a, b;
            scanf("%d%d", &a, &b);
            int pa = find(a), pb = find(b);
            if (pa != pb)
                puts("-1");
            else
                printf("%d\n", max(0, abs(d[a] - d[b]) - 1));
        }
    }
    return 0;
}