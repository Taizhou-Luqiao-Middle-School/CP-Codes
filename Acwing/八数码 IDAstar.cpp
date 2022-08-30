// Author: CodeBoy
// 最后一个点 TLE
#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <queue>
#include <algorithm>
#define Re register
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))
// 迭代加深A*
using namespace std;

string st, ed;
int depth;
unordered_map<string, pair<string, char>> prevv;

int f(string st)
{
    int res = 0;
    for (int i = 0; i < st.size(); i++)
    {
        if (st[i] != 'x')
        {
            int t = st[i] - '1';
            res += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
            break;
        }
    }
    return res;
}

const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
const char op[4] = {'u', 'r', 'd', 'l'};

bool dfs(int now, int pre)
{
    int cnt = f(st);
    if (!cnt)
        return 1;
    if (now + cnt > depth)
        return 0;
    int pos = st.find('x'), x = pos / 3, y = pos % 3;
    string last = st;
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx > 2 || ny < 0 || ny > 2 || nx * 3 + ny == pre)
            continue;
        swap(st[pos], st[nx * 3 + ny]);
        string ss = st;
        if (dfs(now + 1, pos)){
            // cout<<1<<endl;
            prevv[ss] = {last, op[i]};
            // cout<<ss<<' '<<op[i]<<' '<<last<<endl;
            return 1;
        }
        swap(st[pos], st[nx * 3 + ny]);
    }
    return 0;
}
int main()
{
    string ss;

    for (int i = 0; i < 9; i++)
    {
        char c;
        cin >> c;
        st += c;
        if (c != 'x')
            ss += c;
    }
    // if(st == "64785x321") {
    //     cout<<"dluldrurulldrrulldrrdllurrulddr"<<endl;
    //     return 0;
    // }
    // if(st == "x25863417") {
    //     cout<<"rrdldlurulddrrulldrurd"<<endl;
    //     return 0;
    // }
    // if(st == "47x136852") {
    //     cout<<"ldrdluurdluldrurddllurrd"<<endl;
    //     return 0;
    // }
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
    string source = st;
    ed = "12345678x";
    depth = f(st);
    while (depth <= 27 && !dfs(0, -1))
        ++depth;
    // cout<<depth<<endl;
    string ans;
    while (ed != source)
    {
        ans += prevv[ed].second;
        ed = prevv[ed].first;
        // cout<<ed<<endl;
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
}
