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
unordered_map<string, int> dist1, dist2;
unordered_map<string, pair<string, char>> prev1, prev2;
queue<string> q1, q2;

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

string bfs(queue<string> &q, unordered_map<string, int> &da, unordered_map<string, int> &db,
           unordered_map<string, pair<string, char>> &pre)
{
    int dist = da[q.front()];
    while (q.size() && da[q.front()] == dist)
    {
        auto t = q.front();
        q.pop();
        int x, y;
        get_position(x, y, t);
        string last = t;
        for (int i = 0; i < 4; i++)
        {
            t = last;
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
                continue;
            // 交换操作
            swap(t[x * 3 + y], t[nx * 3 + ny]);
            if (da.count(t))
                continue;
            pre[t] = {last, op[i]};
            if (db.count(t))
            {
                return t;
            }
            da[t] = da[last] + 1;
            q.push(t);
            // swap(t[x * 3 + y], t[nx * 3 + ny]); 只放这个的话, 会WA, 原因是前面continue之后没有还原
        }
    }
    return "";
}

string bfs(string A, string B)
{
    q1.push(A);
    dist1[A] = 0;
    string mid;
    q2.push(B);
    dist2[B] = 0;
    while (q1.size() && q2.size())
    {
        if (q1.size() < q2.size())
        {
            mid = bfs(q1, dist1, dist2, prev1);
        }
        else
        {
            mid = bfs(q2, dist2, dist1, prev2);
        }
        if (mid != "")
            break;
    }
    return mid;
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

    string mid = bfs(s, "12345678x");

    string res1, res2;
    string t1 = mid, t2 = t1; // 拷贝中间字符串值

    while (t1 != s)
    {
        res1 += prev1[t1].second;
        t1 = prev1[t1].first; // 上一个状态
    }

    reverse(res1.begin(), res1.end());

    while (t2 != "12345678x")
    {
        char aa = prev2[t2].second;

        if (aa == 'u' || aa == 'd')
            aa = 'u' + 'd' - aa;
        else
            aa = 'l' + 'r' - aa;
        res2 += aa;
        t2 = prev2[t2].first;
    }
    cout << res1 << res2 << endl;

    return 0;
}