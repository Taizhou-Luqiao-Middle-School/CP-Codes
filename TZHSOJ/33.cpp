#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	string c;
	int x, cnt=0, a[1000];
	cin>>c;
	for(int i=0;i<c.size();i+=2){
		a[cnt++] = c[i];
		cout<<c[i]<<endl;
	}
	
	sort(a,a+cnt-1);
	cout<<cnt<<' ';
	cout<<a[cnt-2]<<endl;
	return 0;
}

