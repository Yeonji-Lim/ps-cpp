#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cost[1001][3];
    int dp[1001][3];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
        if(i == 0) continue;
        cost[i][0] += min(cost[i-1][1], cost[i-1][2]);
        cost[i][1] += min(cost[i-1][0], cost[i-1][2]);
        cost[i][2] += min(cost[i-1][1], cost[i-1][0]);
    }
    cout << min(min(cost[n-1][0], cost[n-1][1]), cost[n-1][2]) << '\n';
}