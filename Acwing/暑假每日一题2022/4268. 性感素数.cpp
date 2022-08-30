/*
Author:qianmo
算法：语法题
题目链接：https://www.acwing.com/problem/content/4271/
*/
#include <bits/stdc++.h>
using namespace std;
bool is_prime(int n){
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= (int)sqrt(n); i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}
int main()
{
	int n;
	cin >> n;
	if(is_prime(n) && is_prime(n-6)) cout << "Yes" << endl << n-6;
	else if(is_prime(n) && is_prime(n+6)) cout << "Yes" << endl << n+6;
	else
	{
		cout << "No" << endl;
		for(int i=n;;i++)
		{
			if(is_prime(i) && (is_prime(i+6) || is_prime(i-6)))
			{
				cout << i;
				break;
			}
		}
	}
	return 0;
}