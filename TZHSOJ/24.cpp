#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int y,m;
	cin>>y>>m;
	int day[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(y%100!=0 && y%4==0 || y%400==0){
		day[2] = 29;
	}
	cout<<day[m]<<endl;
	return 0;
}

