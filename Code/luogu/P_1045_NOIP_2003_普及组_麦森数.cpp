// Author: CodeBoy
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 1005, MAX = 500;
int num[N], t[N], a[N];
void mul(bool mo)
{
    memset(t, 0, sizeof t);
    for (int i = 1; i <= MAX; i++)
        for (int j = 1; j <= MAX; j++)
             t[i + j - 1] += mo ? num[i] * a[j] : a[i] * a[j];
    for (int i = 1; i <= MAX; i++)
        t[i + 1] += t[i] / 10, t[i] %= 10;
    mo ? memcpy(num, t, sizeof num) : memcpy(a, t, sizeof a);
}
void calc(int p)
{
    num[1] = 1, a[1] = 2;
    while (p)
    {
        if (p & 1) mul(1);
        p >>= 1;
        mul(0);
    }
}
int main()
{
    int p;
    cin >> p;
    cout << (int)(log10(2) * p + 1) << endl;
    calc(p);
    num[1]--;
    for (int i = 500; i >= 1; i--)
        if (i != 500 && i % 50 == 0)
            printf("\n%d", num[i]);
        else
            printf("%d", num[i]);
    return 0;
}

// // Author: CodeBoy
// #include <iostream>
// #include <cmath>
// #include <cstring>
// using namespace std;
// const int _______ = 1005, ______ = 500;
// int _[_______], ___[_______], __[_______];
// void _________(bool __________)
// {
//     memset(___, 0, sizeof ___);
//     for (int ____ = 1; ____ <= ______; ____++)
//         for (int _____ = 1; _____ <= ______; _____++)
//              ___[____ + _____ - 1] += __________ ? _[____] * __[_____] : __[____] * __[_____];
//     for (int ____ = 1; ____ <= ______; ____++)
//         ___[____ + 1] += ___[____] / 10, ___[____] %= 10;
//     __________ ? memcpy(_, ___, sizeof _) : memcpy(__, ___, sizeof __);
// }
// void ___________(int _____)
// {
//     _[1] = 1, __[1] = 2;
//     while (_____)
//     {
//         if (_____ & 1) _________(1);
//         _____ >>= 1;
//         _________(0);
//     }
// }
// int main()
// {
//     int p;
//     cin >> p;
//     cout << (int)(log10(2) * p + 1) << endl;
//     ___________(p);
//     _[1]--;
//     for (int i = 500; i >= 1; i--)
//         if (i != 500 && i % 50 == 0)
//             printf("\n%d", _[i]);
//         else
//             printf("%d", _[i]);
//     return 0;
// }