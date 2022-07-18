// Date: 2022-07-18 19:27:43
// Problem: 最少交换次数
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/3718/
// Memory Limit: 64 MB
// Time Limit: 1000 ms

// Author: Codeboy

#include <bits/stdc++.h>
using namespace std;
const int N =  1005;
int a[N], b[N], tmp[N], n;

int merge_sort(int l, int r){
	if(l>=r) return 0;
	int mid = l + r >> 1;
	int s = merge_sort(l, mid) + merge_sort(mid + 1, r);
	int i0 = 0, i1 = l, i2 = mid + 1;
	while(i1<=mid && i2 <= r){
		if(a[i1] <= a[i2]) tmp[i0++] = a[i1++];
		else{
			b[a[i2]] += mid - i1 + 1;
			s += mid - i1 + 1;
			tmp[i0++] = a[i2++]; 
		}
	}
	while(i1<=mid) tmp[i0++] = a[i1++];
	while(i2<=r) tmp[i0++] = a[i2++];
	for(int i=l,j=0;i<=r;i++, j++) a[i] = tmp[j];
	return s;
}

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cin>>n;
  	for(int i=1;i<=n;i++) cin>>a[i];
  	
	int cnt = merge_sort(1, n);
	for(int i=1;i<=n;i++) cout<<b[i]<<' ';
	cout<<endl<<cnt<<endl;
	
	return 0;
}
