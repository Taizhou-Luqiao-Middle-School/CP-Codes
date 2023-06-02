#include <iostream>
using namespace std;
int main(){
    int n=0,a=0,b=0,c=0,d=0,i,j;
    char m[1001];
    while(cin>>m[n]){n++;}
    for (i=0;i<=n-1;i++){
        if (m[i]=='a' or m[i]=='A')a++;
        if (m[i]=='b' or m[i]=='B')b++;
        if (m[i]=='c' or m[i]=='C')c++;
        if (m[i]=='d' or m[i]=='D')d++;
    }
    for(j=a+b+c+d;j>=0;j--){
        if(j==a)
        cout<<"A : "<<a<<endl;
        if(j==b)
        cout<<"B : "<<b<<endl;
        if(j==c)
        cout<<"C : "<<c<<endl;
        if(j==d)
        cout<<"D : "<<d<<endl;
    }
}
