// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> specialSort(int N) {
        vector<int>v;
        for(int i=1;i<=N;++i) v.push_back(i);
        stable_sort(v.begin(),v.end(),compare);
        return v;
    }
};