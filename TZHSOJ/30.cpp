#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	string a;
	cin>>a;
	int res = 0;
	for(int i=0;i<a.size();i++){
		int x = a[i] - '0';
		res += x;
	}
	cout<<res<<endl;
	return 0;
}

