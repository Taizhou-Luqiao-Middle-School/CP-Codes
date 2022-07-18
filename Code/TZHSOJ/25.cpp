#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
	return a>b;
}
int main(){
	int a[10];
	for(int i=0;i<3;i++){
		cin>>a[i];
	}
	sort(a,a+3,cmp);
	for(int i=0;i<3;i++){
		cout<<a[i]<<' ';
	}
	return 0;
}

