// Date: 2021-10-18 09:54:14
// Problem: P1379 八数码难题
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1379
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Stauts: AC
// Author: Guan Yongjie
// 迭代加深A*
#define DEBUG 1  //调试开关
#include <bits/stdc++.h>
using namespace std;
string st, ed;//起始状态和目标 
int depth;//搜索深度 
//估价函数，为每个数字的曼哈顿距离之和 
int hfunc(string st) {
	int ans = 0;
	for (register int i = 0; i < st.size(); ++i) {
		if (st[i] == '0') continue;//0不算，否则会WA 
		int j = ed.find(st[i]), r = i / 3, c = i % 3;
		int x = j / 3, y = j % 3;
		//横坐标为/3, 纵坐标为%3 
		ans += abs(r - x) + abs(c - y);
	}
	return ans;
}
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
//IDA_star
//除了估价函数，还有一个显然的优化是记录上一次的操作 
bool dfs(int now, int pre) {
	int cnt = hfunc(st);
	if (!cnt) return 1;
	if (now + cnt > depth) return 0;
	//当前步数+估价>深度限制，立即回溯 
	int pos = st.find('0'), x = pos / 3, y = pos % 3;
	for (register int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx > 2 || ny < 0 || ny > 2 || nx * 3 + ny == pre) continue;
		//数组中的下标为横坐标*3+纵坐标 
		swap(st[pos], st[nx * 3 + ny]);
		if (dfs(now + 1, pos)) return 1;
		swap(st[pos], st[nx * 3 + ny]);
	}
	return 0;
}
int main() {
	cin >> st;
	ed = "123804765";
	depth = hfunc(st);
	while (depth <= 27 && !dfs(0, -1)) ++depth;
	cout << depth << endl;
}
