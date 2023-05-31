#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    int bh, bm, eh, em;
    char s;
    int a[1500] = {0};
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> bh >> s >> bm;
        cin >> s;
        cin >> eh >> s >> em;
        for(int j = bh * 60 + bm; j < eh * 60 + em; j++) {
            a[j] += 1;
        }
    }
    int ans = 0;
    for(int i = 0; i <= 1440; i++) {
        if(a[i] > m) ans += 1;
    }
    cout << ans;
    return 0;
}