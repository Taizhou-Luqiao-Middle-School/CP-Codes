#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	double a;
	cout<<fixed;
	cout.precision(2);
	cin>>a;
	if(a<=1000){
		cout<<a*0.95<<endl;
	} else{
		cout<<950+(a-1000)*0.9<<endl;
	}
	return 0;
}

