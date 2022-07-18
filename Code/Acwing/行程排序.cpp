#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 10005;
int main(){
    int T;
    cin>>T;
    for (int cases = 1; cases <= T; cases ++ ){
        int n;
        cin >> n;
        unordered_map<string, string> next;
        unordered_set<string> S;
        while (n -- )
        {
            string a, b;
            cin >> a >> b;
            next[a] = b;
            S.insert(b);
        }

        string head;
        for (auto& [a, b]: next)
            if (!S.count(a))
            {
                head = a;
                break;
            }

        printf("Case #%d: ", cases);
        while (next[head].size())
        {
            cout << head << '-' << next[head] << ' ';
            head = next[head];
        }
        cout << endl;
    }
    return 0;
}