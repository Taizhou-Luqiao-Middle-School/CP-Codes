// 陆田所写的不是XB写的
#include <bits/stdc++.h>
using namespace std;
 
int md[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 
int yes(string s) {
    int y = 0;
    y += (s[0]^48)*1000;
    y += (s[1]^48)*100;
    y += (s[2]^48)*10;
    y += (s[3]^48)*1;
    return y;
}
 
int getm(string s) {
    int m = 0;
    m += (s[4]^48)*10;
    m += (s[5]^48)*1;
    return m;
}
 
int Dget(string s) {
    int d = 0;
    d += (s[6]^48)*10;
    d += (s[7]^48)*1;
    return d;
}
 
bool isly(int x) {
    if((x % 100 != 0 && x % 4 == 0) || x % 400 == 0) {
        return true;
    }
    else return false;
}
 
int Dget(int y, int m, int d) {
    int days = 0;
    for(int i = 2011; i <= y; i++) {
        if(isly(i - 1)) days += 366;
        else days += 365;
    }
    for(int i = 2; i <= m; i++) {
        if(i == 3 && isly(y)) days += 29;
        else days += md[i - 1];
    }
    days += d - 1;
    return days;
}
 
void check(int days) {
    int d = 0;
    while(d < days) {
        d += 3;
        if(d >= days) {
            cout << "fish";
            return;
        }
        d += 2;
        if(d >= days) {
            cout << "net";
            return;
        }
    }
}
 
signed main() {
    string s;
    cin >> s;
    int y = yes(s);
    int m = getm(s);
    int d = Dget(s);
    int days = Dget(y, m, d) + 1;
    check(days);
    return 0;
}