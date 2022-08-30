#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int LMAX = 410000;
struct Node
{
    int max_val;
    long long sum;
};
int L;
struct Node tree[LMAX];
long long query(int x, int L, int R, int l, int r)
{
    if (l == L && r == R)
    {
        return tree[x].sum;
    }
    int mid = (L + R) >> 1;
    long long ans = 0;
    if (l <= mid)
    {
        ans += query(x << 1, L, mid, l, min(r, mid));
    }
    if (r > mid)
    {
        ans += query((x << 1) + 1, mid + 1, R, max(l, mid + 1), r);
    }
    return ans;
}
void pushup(int x)
{
    tree[x].max_val = max(tree[x << 1].max_val, tree[(x << 1) + 1].max_val);
    tree[x].sum = tree[x << 1].sum + tree[(x << 1) + 1].sum;
}
void mod_update(int x, int L, int R, int l, int r, int val)
{
    if (l == L && r == R)
    {
        if (tree[x].max_val < val)
        {
            return;
        }
    }
    if (L == R)
    {
        tree[x].max_val %= val;
        tree[x].sum = tree[x].max_val;
        return;
    }
    int mid = (L + R) >> 1;
    if (l <= mid)
    {
        mod_update(x << 1, L, mid, l, min(r, mid), val);
    }

    if (r > mid)
    {
        mod_update((x << 1) + 1, mid + 1, R, max(l, mid + 1), r, val);
    }
    pushup(x);
}
void div_update(int x, int L, int R, int l, int r, int val)
{
    if (l == L && r == R)
    {
        if (tree[x].max_val == 0)
        {
            return;
        }
    }
    if (L == R)
    {
        tree[x].max_val /= val;
        tree[x].sum = tree[x].max_val;
        return;
    }
    int mid = (L + R) >> 1;
    if (l <= mid)
    {
        div_update(x << 1, L, mid, l, min(r, mid),  val);
    }

    if (r > mid)
    {
        div_update((x << 1) + 1, mid + 1, R, max(l, mid + 1), r, val);
    }
    pushup(x);
}
void build_tree()
{
    for (int x = L - 1; x; x -= 1)
    {
        pushup(x);
    }
}
int main()
{
    freopen("mseq.in", "r", stdin);
    freopen("mseq.out", "w", stdout);
    int n, q;
    scanf("%d %d", &n, &q);
    for (L = 1; L < n; L <<= 1)
    {
        ;
    }
    for (int i = 0; i < n; i += 1)
    {
        int a;
        scanf("%d", &a);
        tree[L + i].max_val = tree[L + i].sum = a;
    }
    build_tree();
    for (int i = 0; i < q; i += 1)
    {
        int type;
        int l, r, c;
        scanf("%d", &type);
        if (type == 1)
        {
            scanf("%d %d %d", &l, &r, &c);
            mod_update(1, 1, L, l, r, c);
        }
        else if (type == 2)
        {
            scanf("%d %d %d", &l, &r, &c);
            if (c == 1)
            {
                continue;
            }
            div_update(1, 1, L, l, r, c);
        }
        else
        {
            scanf("%d %d", &l, &r);
            printf("%lld\n", query(1, 1, L, l, r));
        }
    }
    return 0;
}