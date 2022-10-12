// #include <bits/stdc++.h>
// using namespace std;
// vector<int> stairs(302, 0);
// vector<vector<int>> DP(302, vector<int>(2, 0));
// int n;

// int main() {
//     cin >> n;
//     for(int i = 1 ; i <= n; i++) {
//         cin >> stairs[i];
//     }
//     DP[1][0] = stairs[1];
//     DP[1][1] = stairs[1];
//     for(int i = 2; i <= n; i++) {
//         DP[i][0] = max(DP[i-2][0], DP[i-2][1]) + stairs[i];
//         DP[i][1] = DP[i-1][0] + stairs[i];
//     }
//     cout << max(DP[n][0], DP[n][1]) << '\n';
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int dp[301][2];
int fl[301];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> fl[i];
    }

    /*어떤 계단에서의 최댓값 = max(한칸 전 계단에서의 최댓값, 두칸 전 계단에서의 최댓값)*/


}