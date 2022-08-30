#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	
	cout<<a/b<<' '<<fixed<<setprecision(2)<<(float)a/b<<endl;
	return 0;
}

