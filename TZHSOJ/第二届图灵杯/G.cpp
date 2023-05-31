#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1010;

struct Node {
    char c;
    int m;
} a[Maxn];

bool cmp(Node a, Node b) {
    return a.c == b.c ? a.m < b.m : a.c <= b.c;
}

signed main(){
    int n, v, w;
    cin >> n >> v >> w;
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        a[i].c = c;
        int h, m;
        cin >> c >> h >> c >> m;
        a[i].m += h * 60 + m;
    }
    sort(a + 1, a + n + 1, cmp);
    int min = a[1].m, k=1;
    char mic = a[1].c;
    for(int i = 1; i <= n; i++) {
        if(a[i].c == mic and k < v  and a[i].m <= w + min) {
            k += 1;
        }
        else {
            ans += 1;
            min = a[i].m;
            mic = a[i].c;
            k = 1;
        }
    }
    cout << ans;
    return 0;
}