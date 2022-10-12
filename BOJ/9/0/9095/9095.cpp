#include <bits/stdc++.h>
using namespace std;
int dp[11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill_n(dp, 11, 0);
    int n, T;
    cin >> T;
    while(T--) {
        cin >> n;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for(int i = 4; i <= n; i++) {
            if(dp[i] == 0) dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        cout << dp[n] << '\n';
    }
}