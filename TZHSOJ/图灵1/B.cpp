#include <iostream>
using namespace std;

signed main(){
    int n;
    cin>>n;
    int sum = 0;
    while (n){
        sum += n%2;
        n = n /2 ;
    }
    cout<<sum;
    return 0;
}