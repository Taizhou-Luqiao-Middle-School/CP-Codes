#include <bits/stdc++.h>
using namespace std;

bool LeapYear(int y) {
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
        return true;
    }
    else {
        return false;
    }
}

int main(){
    int y, m, d;
    cin >> y >> m;
    int w;
    if(m == 4 || m == 6 || m == 9 || m == 11) {
        d = 30;
    }
    if(m == 2) {
        if(LeapYear(y)) d = 29;
        else d = 28;
    }
    else d = 31;
    
    if(m == 1 || m == 2) {
        y -= 1;
        m += 12;
    }
    w = (1+2*m+3*(m+1)/5+y+y/4-y/100+y/400) % 7;
    
    cout << " Sun Mon Tue Wed Thu Fri Sat" << endl;
    if(w != 6) {
        for(int i = 0; i <= w; i++) cout << "    ";
    }
    int k;
    if(w == 6) k = -1;
    else k = w;
    for(int i = 1; i <= d; i++) {
        k += 1;
        if(k == 7) {
            cout << endl;
            k = 0;
        };
        printf("%4d", i);
    }
    return 0;
}
