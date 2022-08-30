#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps = 0.005;
int main(){
	double a,b,c;
	cin>>a>>b>>c;
	cout<<fixed;
	cout.precision(2);
	double delta = b*b-4*a*c;
	if(delta<eps&&delta>0)  delta = 0;
	if(delta < 0){
		cout<<"No answer!"<<endl; 
		return 0; 
	}
	double x1 = (-b+sqrt(delta))/2/a;
	double x2 = (-b-sqrt(delta))/2/a;
	if(delta == 0) cout<<x1<<endl;
	else cout<<x1<<endl<<x2<<endl;
	return 0;
}

