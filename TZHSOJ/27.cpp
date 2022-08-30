#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int main(){
	ll x;
	cin>>x;
	ll res = 0;

	for(int i=1;i<=x;i++){
		if(x%i==0){
			res += i;
		}
	}
	cout<<res<<endl;
	return 0;
}

