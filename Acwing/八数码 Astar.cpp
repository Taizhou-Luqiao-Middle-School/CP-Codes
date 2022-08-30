// Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <queue>
#include <algorithm>
#define Re register
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))
using namespace std;
typedef long long ll;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
const char op[4] = {'u', 'r', 'd', 'l'};
string s;

int f(string st)
{
    int res = 0;
    for (int i = 0; i < st.size(); i++)
    {
        if (st[i] != 'x')
        {
            int t = st[i] - '1';
            res += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
        }
    }
    return res;
}
bool check(int x, int y)
{
    return (x < 3 && x >= 0 && y < 3 && y >= 0);
}

void get_position(int &x, int &y, string &now)
{
    for (int i = 0; i < now.size(); i++)
    {
        if (now[i] == 'x')
        {
            x = i / 3;
            y = i % 3;
            break;
        }
    }
}
void bfs(string s)
{
    unordered_map<string, int> dist;
    unordered_map<string, pair<string, char>> prev;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> q;
    dist[s] = 0;
    q.push({f(s), s});
    while (q.size())
    {
        auto t = q.top();
        q.pop();

        string now = t.second;
        if (now == "12345678x")
            break;

        int x, y, step = dist[now];

        get_position(x, y, now);

        string last = now;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny))
            {
                swap(now[x * 3 + y], now[nx * 3 + ny]);

                if (!dist.count(now) || dist[now] > step + 1)
                {
                    dist[now] = dist[last] + 1;
                    prev[now] = {last, op[i]};
                    q.push({f(now) + dist[now], now});
                }

                swap(now[x * 3 + y], now[nx * 3 + ny]);
            }
        }
    }

    string ans, end = "12345678x";

    while (end != s)
    {
        ans += prev[end].second;
        end = prev[end].first;
    }

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i];
    }

    cout << endl;
}

int main()
{
    string ss;

    for (int i = 0; i < 9; i++)
    {
        char c;
        cin >> c;
        s += c;
        if (c != 'x')
            ss += c;
    }

    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (ss[i] < ss[j])
                cnt++;
        }
    }

    if (cnt % 2 == 1)
    {
        cout << "unsolvable" << endl;
        return 0;
    }

    bfs(s);

    return 0;
}