#include <iostream>
using namespace std;
int dp[15][15] ={0};

int find(int k, int n) {
    if(dp[k][n] != 0) return dp[k][n];
    if(k == 0) dp[k][n] = n;
    else if(n == 1) dp[k][n] = find(k-1, n);
    else dp[k][n] = find(k-1, n) + find(k, n-1);
    return dp[k][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t, k, n;
    cin >> t;
    while(t-- != 0) {
        cin >> k >> n;
        cout << find(k, n) << endl;
    }
    return 0;
}