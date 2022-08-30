#include <iostream>
using namespace std;
long long cnt;
int main(){
	int max = 1<<30;
	for(int i=1;i<=max;i++){
		if(!(i ^ 2 * i ^ 3 * i)) cnt ++;
	}
	cout<<cnt<<endl;
	return 0;
}