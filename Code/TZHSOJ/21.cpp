#include <iostream>
#include <algorithm>
using namespace std;
bool flag1 = false, flag2 = false;
void query(int a, int b, int c){
	if(a*a+b*b == c*c){
		flag1 = true;
	}
	if(a+b>c&&a-b<c) {
		flag2 = true;
	}
}
int main(){
	int a, b, c;
	cin>>a>>b>>c;
	query(a,b,c);
	query(b,c,a);
	query(c,a,b);
	if(flag2){
		if(flag1){
			cout<<"Yes!"<<endl;
		} else{
			cout<<"No!"<<endl;
		}
	} else {
		cout<<"Error!"<<endl;
	}
	
	return 0;
}

