// #include <bits/stdc++.h>
// using namespace std;
// int dp[11];

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     dp[1] = 1;
//     dp[2] = 2;
//     dp[3] = 4;
//     for(int i = 4; i < 11; i++) {
//         dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
//     }
//     int n, T;
//     cin >> T;
//     while(T--) {
//         cin >> n;
//         cout << dp[n] << '\n';
//     }
// }

// 20230224
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int dp[11] = {};
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 4; i <= n; i++) {
            if(dp[i] != 0) continue;
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        cout << dp[n] << '\n';
    }
}