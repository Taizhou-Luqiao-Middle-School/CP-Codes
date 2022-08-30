#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void read(int &x){
    int f=1;char c=getchar();x=0;
    while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
    while(isdigit(c)){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    x*=f;
}
int n;
vector<int> a;
int main(){
    read(n); 
    int op, x;
    while(n--){
        read(op),read(x);
        if(op == 1) a.insert(lower_bound(a.begin(), a.end(), x), x);
        else if(op == 2) a.erase(lower_bound(a.begin(), a.end(), x));
        else if(op == 3) printf("%d\n", lower_bound(a.begin(), a.end(), x) - a.begin() + 1);
        else if(op == 4) printf("%d\n", a[x - 1]);
        else if(op == 5) {
            printf("%d\n", *--lower_bound(a.begin(), a.end(), x));
        }
        else if(op == 6) printf("%d\n", *upper_bound(a.begin(), a.end(), x));
    }
    return 0;
}