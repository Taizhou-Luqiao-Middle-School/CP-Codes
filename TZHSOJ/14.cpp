#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	double a,b;
	cin>>a>>b;
	
	cout<<int(a/b)<<' '<<(int)a%(int)b;
	return 0;
}

