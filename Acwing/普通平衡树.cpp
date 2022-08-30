// Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Re register
using namespace std;
typedef long long ll;
const int N = 100010, INF = 1e8;
int root, idx;
int n;
struct Node
{
    int l, r;
    int key, val;
    int cnt, size;
} tr[N];

// 更新该节点
void pushup(int p)
{
    tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + tr[p].cnt;
}

// 新建节点
int get_node(int key)
{
    tr[++idx].key = key;
    tr[idx].val = rand();
    tr[idx].cnt = tr[idx].size = 1;
    return idx;
}

/*
旋转操作的含义：
    在不影响搜索树性质的前提下，把和旋转方向相反的子树变成根节点
    （如左旋，就是把右子树变成根节点）
    不影响性质，并且在旋转过后，跟旋转方向相同的子节点变成了原来的根节点
    （如左旋，旋转完之后的左子节点是旋转前的根节点）
*/

// 右旋
void zig(int &p)
{
    int q = tr[p].l;
    tr[p].l = tr[q].r, tr[q].r = p, p = q;
    pushup(tr[p].r), pushup(p);
}

// 左旋
void zag(int &p)
{
    int q = tr[p].r;
    tr[p].r = tr[q].l, tr[q].l = p, p = q;
    pushup(tr[p].l), pushup(p);
}

// 建树
void build()
{
    get_node(-INF), get_node(INF);
    root = 1, tr[1].r = 2;
    pushup(root);
    if (tr[1].val < tr[2].val)
        zag(root);
}

// 插入节点
void insert(int &p, int key)
{
    if (!p)
        p = get_node(key);
    else if (tr[p].key == key)
        tr[p].cnt++;
    else if (tr[p].key > key)
    {
        insert(tr[p].l, key);
        if (tr[tr[p].l].val > tr[p].val)
            zig(p);
    }
    else
    {
        insert(tr[p].r, key);
        if (tr[tr[p].r].val > tr[p].val)
            zag(p);
    }
    pushup(p);
}

// 删除节点
void remove(int &p, int key)
{
    if (!p)
        return;
    if (tr[p].key == key)
    {
        if (tr[p].cnt > 1)
            tr[p].cnt--;
        else if (tr[p].l || tr[p].r) // 有子树, 不能直接删除
        {
            if (!tr[p].r || tr[tr[p].l].val > tr[tr[p].r].val)
            {
                zig(p);
                remove(tr[p].r, key);
            }
            else
            {
                zag(p);
                remove(tr[p].l, key);
            }
        }
        else
            p = 0;
    }
    else if (tr[p].key > key)
        remove(tr[p].l, key);
    else
        remove(tr[p].r, key);

    pushup(p);
}

int grbk(int p, int key)
{
    if (!p)
        return 0;
    if (tr[p].key == key)
        return tr[tr[p].l].size + 1;
    if (tr[p].key > key)
        return grbk(tr[p].l, key);
    return tr[tr[p].l].size + tr[p].cnt + grbk(tr[p].r, key);
}

int gkbr(int p, int rank)
{
    if (!p)
        return INF;
    if (tr[tr[p].l].size >= rank)
        return gkbr(tr[p].l, rank);
    if (tr[tr[p].l].size + tr[p].cnt >= rank)
        return tr[p].key;
    return gkbr(tr[p].r, rank - tr[tr[p].l].size - tr[p].cnt);
}

int get_prev(int p, int key)
{
    if (!p)
        return -INF;
    if (tr[p].key >= key)
        return get_prev(tr[p].l, key);
    return max(tr[p].key, get_prev(tr[p].r, key));
}

int get_next(int p, int key)
{
    if (!p)
        return INF;
    if (tr[p].key <= key)
        return get_next(tr[p].r, key);
    return min(tr[p].key, get_next(tr[p].l, key));
}

int main()
{
    build();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int op, x;
        scanf("%d%d", &op, &x);
        if (op == 1)
            insert(root, x);
        else if (op == 2)
            remove(root, x);
        else if (op == 3)
            printf("%d\n", grbk(root, x) - 1);
        else if (op == 4)
            printf("%d\n", gkbr(root, x + 1));
        else if (op == 5)
            printf("%d\n", get_prev(root, x));
        else
            printf("%d\n", get_next(root, x));
    }
    return 0;
}