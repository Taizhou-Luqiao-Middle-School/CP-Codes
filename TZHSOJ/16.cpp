#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
	int a,b,h;
	cin>>a>>b>>h;
	cout<<fixed<<setprecision(2)<<(a+b)/2.0*h<<endl;
	return 0;
}

