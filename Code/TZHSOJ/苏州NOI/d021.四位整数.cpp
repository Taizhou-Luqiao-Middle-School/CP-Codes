#include <iostream>
 
using namespace std;
 
int main()
{
    int i = 1000;
    do
    {
        int ab = i/100;
        int cd = i - ab*100;
        if((ab+cd)^2 == i)
        {
            cout << i <<endl;
        }
        i++;
    }while(i<=9999);
}