// Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long LL;

struct Point
{
    LL x, y;
};

Point get(LL n, LL a)
{
    if (n == 0)
        return {0, 0};
    LL block = 1ll << n * 2 - 2;
    auto p = get(n - 1, a % block);
    LL len = 1ll << n - 1;
    int z = a / block;
    LL x = p.x, y = p.y;
    if (z == 0)
        return {y, x};
    else if (z == 1)
        return {x, y + len};
    else if (z == 2)
        return {x + len, y + len};
    else
        return {len * 2 - 1 - y, len - 1 - x};
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        LL n, a, b;
        scanf("%lld%lld%lld", &n, &a, &b);
        auto pa = get(n, a - 1);
        auto pb = get(n, b - 1);
        double dx = pa.x - pb.x, dy = pa.y - pb.y;
        printf("%.0lf\n", sqrt(dx * dx + dy * dy) * 10);
    }
    return 0;
}