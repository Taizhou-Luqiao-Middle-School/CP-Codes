#include<iostream>
using std::cout;
using std::endl;
#define f(a) (a)*(a)*(a)
int main() {
    for (int i = 100;i < 1000;i++)
        if (f(i % 10) + f(i / 10 % 10) + f(i / 100 % 10) == i)
            cout << i << endl;
    return 0;
}