#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int h[N];
int ans[N];
int tr[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}

int sum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
        scanf("%d", &h[i]);

    for (int i = 1; i <= n; i++)
        tr[i] = lowbit(i);

    for (int i = n; i; i--)
    {
        int k = h[i] + 1;
        int l = 1, r = n;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (sum(mid) >= k)
                r = mid;
            else
                l = mid + 1;
        }
        ans[i] = r;
        add(r, -1);
    }

    for (int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);

    return 0;
}
