// Date: 2022-07-17 13:39:57
// Problem: T250901 伟大的神
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T250901?contestId=73946
// Memory Limit: 256 MB
// Time Limit: 1000 ms

// Author: Codeboy

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, i;
    cin >> n >> m >> k;
    if (n == m)
    {
        for (i = 0; i < m; i++)
        {
            if (i % 2 == 1)
                cout << 'r';
            else
                cout << 'l';
        }
        return 0;
    }
    for (i = 0; i < m; i++)
    {
        if (i % 2 == 1)
            cout << 'r';
        else
            cout << 'l';
    }
	cout<<'r';
	i++;
    bool flag = 0;
    int kk = k;
    while (i < n)
    {
        for (;i < n; k--)
        {
            if (k == 0)
                k = kk;
            for (int j = 0; j < kk-1 && i < n-1; j++)
            {
                if (flag == 0)
                    cout << 'l';
                else
                    cout << 'r';
                i++;
            }

            for (int j = 0; j < m-1 && i < n-1; j++)
            {
                if (i % 2 == 1)
                {
                    cout << 'r';
                    flag = 0;
                }
                else
                {
                    cout << 'l';
                    flag = 1;
                }
                i++;
            }
            if(flag==0) cout<<'r';
            else cout<<'l';
            i++;
        }
    }

    return 0;
}
