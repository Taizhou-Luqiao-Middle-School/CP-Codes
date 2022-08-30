#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int a,b,c,d;
	for(a=1;a<10;a++){
		for(b=0;b<10;b++){
			for(c=0;c<10;c++){
				for(d=0;d<10;d++){
					int x = a*10+b, y = c*10+d, z = a*1000+b*100+c*10+d;
					if((x+y)*(x+y)==z){
						cout<<z<<endl;
					}
					
				}
			}
		}
	}
	return 0;
}

