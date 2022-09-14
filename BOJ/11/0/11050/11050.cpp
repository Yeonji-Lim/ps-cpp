#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> DP(11, vector<int>(11, 0));

int combination(int n, int k) {
    if(DP[n][k] != 0) return DP[n][k];
    if(k == 0 || k == n) DP[n][k] = 1;
    else DP[n][k] = combination(n-1, k-1) + combination(n-1, k);
    return DP[n][k];
}

int main() {
    int n, k;
    DP[0][0] = 1;
    DP[1][0] = 1;
    DP[1][1] = 1;
    cin >> n >> k;
    cout << combination(n, k) << '\n';
    return 0;
}