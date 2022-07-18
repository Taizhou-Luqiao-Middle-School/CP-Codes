#include <iostream>
#include <algorithm>
using namespace std;

int f(int x){
	if(x>0) return 1;
	if(x<0) return -1;
	return 0;
}
int main(){
	int a;
	cin>>a;
	cout<<f(a)<<endl;
	return 0;
}

