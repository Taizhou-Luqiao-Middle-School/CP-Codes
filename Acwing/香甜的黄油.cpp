// Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 810, M = 3000, INF = 0x3f3f3f3f;
int n, m, p;
int id[N];
int h[N], e[M], w[M], ne[M], idx;
int dist[N], q[N];
bool st[N];
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int spfa(int start)
{
    // memset(st, 0, sizeof st);

    memset(dist, 0x3f, sizeof dist);
    dist[start] = 0;
    int hh = 0, tt = 1;
    q[0] = start, st[start] = true;
    while (hh != tt)
    {
        int t = q[hh++];
        if (hh == N)
            hh = 0;
        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])
                {
                    q[tt++] = j;
                    if (tt == N)
                    {
                        tt = 0;
                    }
                    st[j] = true;
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int j = id[i];
        if (dist[j] == INF)
            return INF;
        res += dist[j];
    }
    return res;
}



int main()
{
    cin >> n >> p >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> id[i];
    }
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    int res = INF;
    for (int i = 1; i <= p; i++)
    {
        res = min(res, spfa(i));
    }
    cout << res << endl;
    return 0;
}
