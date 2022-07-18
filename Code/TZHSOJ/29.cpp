#include <iostream>
#include <algorithm>
using namespace std;
string a;
int main(){
	cin>>a;
	int res=0;
	for(int i=0;i<a.size();i++){
		if(a[i]=='a'||a[i]=='A')
			res+=1;
	}
	cout<<res<<endl;
	return 0;
}

