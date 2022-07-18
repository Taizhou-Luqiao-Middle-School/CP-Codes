#include <iostream>
#include <algorithm>
const int maxn = 105;
int a[maxn];
using namespace std;
int main()
{
    int b,i=0;
    while(cin >> b)
    {
        a[i++] = b;
    }
    sort(a,a+i);
    cout << i << " " << a[i-1];
}