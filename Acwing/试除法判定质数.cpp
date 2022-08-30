#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x < 2)
        {
            cout << "No" << endl;
            continue;
        }
        int flag = true;
        for (int j = 2; j <= x / j; j++)
        {
            if (x % j == 0)
            {
                cout << "No" << endl;
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "Yes" << endl;
    }

    return 0;
}