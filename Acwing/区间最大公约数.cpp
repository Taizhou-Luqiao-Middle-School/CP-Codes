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
const int N = 500010;
int n, m;

struct Node
{
    int l, r;
    ll v, d;
} tr[N * 4];
ll a[N];

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

void pushup(Node &u, Node &l, Node &r)
{
    u.v = l.v + r.v;
    u.d = gcd(l.d, r.d);
}

void pushup(int u)
{
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r)
{
    if (l == r)
    {
        ll b = a[r] - a[r - 1];
        tr[u] = {l, r, b, b};
    }
    else
    {
        tr[u].l = l, tr[u].r = r;
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int p, ll v)
{
    if (tr[u].l == p && tr[u].r == p)
    {
        ll b = tr[u].v + v;
        tr[u] = {p, p, b, b};
    }
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (p <= mid)
            modify(u << 1, p, v);
        else
            modify(u << 1 | 1, p, v);
        pushup(u);
    }
}

Node query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u];
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid)
            return query(u << 1, l, r);
        else if (l > mid)
            return query(u << 1 | 1, l, r);
        else
        {
            auto left = query(u << 1, l, r);
            auto right = query(u << 1 | 1, l, r);
            Node res;
            pushup(res, left, right);
            return res;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    build(1, 1, n);

    int l, r;
    ll d;
    char op[2];
    while (m--)
    {
        scanf("%s%d%d", op, &l, &r);
        if (*op == 'Q')
        {
            auto left = query(1, 1, l);
            Node right({0, 0, 0, 0});
            if (l + 1 <= r)
                right = query(1, l + 1, r);
            printf("%lld\n", abs(gcd(left.v, right.d)));
        }
        else
        {
            scanf("%lld", &d);
            modify(1, l, d);
            if (r + 1 <= n)
                modify(1, r + 1, -d);
        }
    }
    return 0;
}