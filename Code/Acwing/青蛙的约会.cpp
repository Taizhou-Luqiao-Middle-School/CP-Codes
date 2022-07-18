#include <iostream>
using namespace std;
typedef long long LL;
LL x0, y0, x, y, m, n, l;
LL exgcd(LL a, LL b){
    if(b==0){
        x0 = 1;
        y0 = 0;
        return a;
    }

    LL d = exgcd(b, a%b);

    int tmpx = x0;
    x0 = y0;
    y0 = tmpx - a/b*y0;
    return d;
}
int main()
{
    LL a, b, m, n, L;
    cin >> a >> b >> m >> n >> L;

    LL d = exgcd(m - n, L);
    if ((b - a) % d) puts("Impossible");
    else
    {
        x0 *= (b - a) / d;
        LL t = abs(L / d);
        cout << (x0 % t + t) % t << endl;
    }

    return 0;
}