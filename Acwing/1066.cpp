// Date: 2022-07-16 11:25:58
// Problem: 小国王
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1066/
// Memory Limit: 64 MB
// Time Limit: 1000 ms

// Author: Codeboy

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 12, M = 1 << 10, K = 110;

int n, m, cnt[M];
vector<int> state;
vector<int> head[M];
ll f[2][K][M];

bool check(int state)
{
    for (int i = 0; i < n; i++)
    {
        if ((state >> i & 1) && (state >> i + 1 & 1))
            return false;
    }
    return true;
}

int count(int state)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        res += state >> i & 1;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < 1 << n; i++)
    {
        if (check(i))
        {
            state.push_back(i);
            cnt[i] = count(i);
        }
    }
    for (int i = 0; i < state.size(); i++)
    {
        for (int j = 0; j < state.size(); j++)
        {
            int a = state[i], b = state[j];
            if ((a & b) == 0 && check(a | b))
            {
                head[i].push_back(j);
            }
        }
    }
    f[0][0][0] = 1;
    for (int i = 1; i <= n + 1; i++)
        for (int j = 0; j <= m; j++)
			for(int a = 0; a < state.size(); a++){
			    f[i&1][j][a] = 0;
			    for (int b : head[a])
	            {
	                int c = cnt[state[a]];
	                if (j >= c)
	                    f[i & 1][j][a] += f[(i - 1) & 1][j - c][b];
        	    }
			}
	            
    cout << f[(n + 1) & 1][m][0] << endl;
    return 0;
}
