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
int n;
struct Node
{
    int v;
    Node *l, *r;
} *root = nullptr;

Node *New(int v)
{
    Node *t = new Node;
    t->v = v;
    t->l = nullptr;
    t->r = nullptr;
    return t;
}

Node *Insert(Node *r, int v)
{
    if (r == nullptr)
        return New(v);
    if (r->v == v)
        return r;
    if (v > r->v)
        r->r = Insert(r->r, v);
    else
        r->l = Insert(r->l, v);
    return r;
}

void dfs(Node *r, int mo)
{
    if (r == nullptr)
        return;
    if (mo == 0)
        cout << r->v << ' ';
    dfs(r->l, mo);
    if (mo == 1)
        cout << r->v << ' ';
    dfs(r->r, mo);
    if (mo == 2)
        cout << r->v << ' ';
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        root = Insert(root, t);
    }

    dfs(root, 0);
    puts("");
    dfs(root, 1);
    puts("");
    dfs(root, 2);
    puts("");
    return 0;
}