// Date: 2022-07-18 18:58:48
// Problem: 最少交换次数
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/3718/
// Memory Limit: 64 MB
// Time Limit: 1000 ms

// Author: Codeboy

#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, b[N], cnt;
int a[N];
int tr[N];

int lowbit(int x){
	return x & -x;
}

void add(int x, int k){
	for(int i=x;i<=n;i+=lowbit(i)) tr[i] += k;
}

int query(int x){
	int sum = 0;
	for(int i=x;i;i-=lowbit(i)) sum += tr[i];
	return sum;
}

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]] += query(n) - query(a[i] - 1);
		cnt += b[a[i]];
		add(a[i], 1);
	}
	for(int i=1;i<=n;i++){
		cout<<b[i]<<' ';
	}
	cout<<endl<<cnt<<endl;
	// for(int i=0;i<n-1;i++){
		// for(int j=n-1;j>i;j--){
			// if(a[j]<a[j-1]){
				// cnt ++;
				// swap(a[j], a[j-1]);
			// }
		// }
	// }
	// cout<<cnt<<endl;

	return 0;
}
