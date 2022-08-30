// Date: 2022-07-16 20:00:16
// Problem: B - Gift Tax
// Contest: AtCoder - AtCoder Regular Contest 144
// URL: https://atcoder.jp/contests/arc144/tasks/arc144_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

// Author: Codeboy

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    ll l = *min_element(nums.begin(), nums.end());
    ll r = *max_element(nums.begin(), nums.end());
    ll ans = l;
    while (l <= r)
    {
        ll mid = l + r >> 1;
        ll x = 0, y = 0;
        for (auto v : nums)
        {
            if (v > mid)
            {
                x += (v - mid) / b;
            }
            else
            {
                y += (mid - v + a - 1) / a;
            }
        }
        if (x >= y)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
