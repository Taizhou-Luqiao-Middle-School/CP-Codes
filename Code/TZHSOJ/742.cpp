#include <iostream>
#include <algorithm>
using namespace std;
int a[10000];
int f[10000];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		f[i] = 1;
		for(int j=0;j<i;j++){
			if(a[i]>a[j]) f[i] = max(f[i], f[j]+1);
		}
	}
	int res = 0;
	for(int i=0;i<n;i++){
		res = max(res, f[i]);
	}
	cout<<res<<endl;
	return 0;
}

