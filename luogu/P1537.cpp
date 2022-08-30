// Date: 2021-10-19 08:22:27
// Problem: P1537 弹珠
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1537
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Stauts: ACcept
// Author: Guan Yongjie

#define DEBUG 1  //调试开关
#include <bits/stdc++.h>
using namespace std;

#define uns unsigned
#define ll long long
#define use_cin_cout do { ios::sync_with_stdio(false); cin.tie(); } while (false)
#define endl '\n'

const ll inf_ll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const int maxv = 6e4 + 5, maxn = 2e4 + 5;

int sum, collection;
int dp[maxv], a[maxn];

int main() {
	use_cin_cout;
	
	while (true) {
		collection++;
		
		bool end = true;
		sum = 0;
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		
		int j = 1;
		for (int i = 1; i <= 6; i++) {
			int t;
			cin >> t;
			sum += t * i;
			if (t != 0) end = false;
			
			int k = 1;
			while (k <= t) {
				a[j++] = k * i;
				t -= k;
				k <<= 1;
			}
			if (t > 0) a[j++] = t * i;
		}
		
		if (end) return 0;
		
		cout << "Collection #" << collection << ":" << endl;
		
		if (sum & 1) {
			cout << "Can't be divided." << endl << endl;
			continue;
		}
		
		bool flag = false;
		for (int i = 1; i < j; i++) {
			for (int v = (sum >> 1); v >= a[i]; v--) {
				dp[v] = max(dp[v], dp[v - a[i]] + a[i]);
				
				if (dp[v] == (sum >> 1)) {
					flag = true;
					break;
				}
			}
		}
		
		if (flag) cout << "Can be divided." << endl << endl;
		else cout << "Can't be divided." << endl << endl;
	}
	
	return 0;
}

