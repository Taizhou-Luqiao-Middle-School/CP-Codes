// 本地过，OJ上WA
#include <iostream>
using namespace std;

signed main(){
    float n;
    cin>>n;
    if (n<=3){
        printf("10");
    }
    else {
        int sum=10;
        n-=3;
        while(n>=0){
            n-=1;
            sum+=2;
        }
        printf("%d",sum);
    }
    return 0;
}

