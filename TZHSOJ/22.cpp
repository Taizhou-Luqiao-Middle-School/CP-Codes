#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	double a, b;
	cout<<fixed;
	cout.precision(2);
	string op;
	cin>>a>>b>>op;
	if(op == "-") cout<<a-b<<endl;
	if(op == "+") cout<<a+b<<endl;
	if(op == "/") cout<<a/b<<endl;
	if(op == "*") cout<<a*b<<endl;
	return 0;
}

