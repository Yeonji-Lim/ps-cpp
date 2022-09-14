#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> mat(501, vector<int>(2, 0));
vector<vector<int>> DP(501, vector<int> (501, -1));

int calDP(int i, int j) {
    if(DP[i][j] != -1) return DP[i][j];
    int ret = INT_MAX;
    for(int k = i; k < j; k++) {
        ret = min(ret, calDP(i, k)+calDP(k+1, j)+mat[i][0]*mat[k][1]*mat[j][1]);
    }
    return DP[i][j] = ret;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> mat[i][0] >> mat[i][1];
        DP[i][i] = 0;
    }
    cout << calDP(0, n-1) << '\n';
    return 0;
}