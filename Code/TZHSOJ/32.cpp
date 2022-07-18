#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int x, a[1000];
	cin>>x;
	for(int i=0;i<x;i++){
		cin>>a[i];
	}
	sort(a,a+x);
	cout<<a[x-1]<<endl;
	return 0;
}

