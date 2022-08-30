#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int a[100005],b[100005];
int m=0;
unordered_map<int, int> S;

int get(int x)
{
    if (S.count(x) == 0)
        S[x] = ++m;
    return S[x];
}


// vector<int> findRelativeRanks(vector<int>& score) {
//         int n = score.size();
//         vector<pair<int, int>> arr;
//         for (int i = 0; i < n; ++i) {
//             arr.emplace_back(make_pair(-score[i], i));
//         }


//         sort(arr.begin(), arr.end());
//         vector<int> ans(n);
//         for (int i = 0; i < n; ++i) {
//             ans[arr[i].second] = i + 1;
//         }
//         return ans;
//     }

// vector<int> findRelativeRanks(vector<int> &score)
//     {
//         map<int, int, greater<int>> m;
//         for (int i = 0; i < score.size(); i++)
//             m[score[i]] = i;

//         vector<int> res(score.size());
//         auto it = m.begin();

//         for (int i = 0; i < score.size(); i++)
//         {
//                 res[(*it).second] = i + 1;
//             it++;
//         }

//         return res;
//     }

int n;

bool ele_rank(const vector<int>& arr, vector<int>& arr_rank)
{
    arr_rank.clear();
    arr_rank.resize(arr.size());
    int rnk = 1;
    arr_rank[0] = rnk;
    for (vector<int>::size_type i = 1; i != arr.size(); ++i)
    {
        if (arr[i] == arr[i-1])
        {
            arr_rank[i] = rnk;
        }
        else
        {
            rnk = i+1;
            arr_rank[i] = rnk;
        }
    }
    return true;
}
int main(){
    scanf("%d",&n);
    int t=0;
    m=0;
    vector<int> arr;

    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        arr.push_back(tmp);
        t+=tmp;
    }
    vector<int> arr_rank;
    ele_rank(arr, arr_rank);
    for (vector<int>::size_type i = 0; i != arr.size(); ++i)
    {
        cout << arr[i] << ":\t" << arr_rank[i] << endl;
    }
    int line = floor(t/n*1.2);
    for(int i=0;i<n;i++){
        if(arr[i]<line) printf("0 ");
        else {
            printf("%d ",arr_rank[i]);
        }
    }
    return 0;
}



