#include <bits/stdc++.h>
using namespace std;
const int LXB = 1e5;

int a[LXB];
int ans[LXB];

signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans[n] += a[i];
    }
    for (int i = 1; i < n; i += 2) {
        ans[n] -= a[i] * 2;
    }
    for (int i = n - 1; i >= 2; i--) {
        ans[i] = 2 * a[i] - ans[i + 1];
    }
    ans[1] = a[n] * 2 - ans[n];
    for (int i = 1; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << ans[n];
}