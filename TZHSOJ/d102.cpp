#include <bits/stdc++.h>
using namespace std;
int main()
{
    double s;
    cin>>s;
    if(s<=3)
        cout<<"10.00";
    else if(s<=5)
        printf("%.2f",10+(s-3)*1.8);
    else
        printf("%.2f",13.6+(s-5)*2.7);
}
