// Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> num;

vector<int> mul(vector<int> a, int b)
{
    vector<int> res;
    int t = 0;
    for (int i = 0; i < a.size() || t; i++)
    {
        if (i < a.size())
            t += a[i] * b;
        res.push_back(t % 10);
        t /= 10;
    }
    while (res.size() > 1 && res.back() == 0)
    {
        res.pop_back();
    }
    return res;
}
int main()
{
    string A;
    int b;
    cin >> A >> b;
    vector<int> a;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        a.push_back(A[i] - '0');
    }
    vector<int> res = mul(a, b);
    for (int i = res.size() - 1; i >= 0; i--)
    {
        printf("%d", res[i]);
    }
    return 0;
}