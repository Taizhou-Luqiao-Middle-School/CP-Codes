#include <bits/stdc++.h>
using namespace std;

int A[100][100];
int B[100][100];
int C[100][100];

signed main(){
    int m ,n ,r;
    cin >> m >> n >> r;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < r; j++) {
            cin >> B[i][j];
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < r; j++) {
            C[i][j] = 0;
            for(int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << m << " " << r << endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < r; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
