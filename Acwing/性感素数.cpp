// Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e8 + 5;
bool query(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    bool nm6 = query(n - 6), na6 = query(n + 6);
    if (query(n) && (nm6 || na6))
    {
        cout << "Yes" << endl;
        if (nm6)
            cout << n - 6 << endl;
        else
            cout << n + 6 << endl;
    }
    else
    {
        cout << "No" << endl;
        for (int i = n + 1; i < N; i++)
        {
            bool im6 = query(i - 6), ia6 = query(i + 6);
            if (query(i) && (im6 || ia6))
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}