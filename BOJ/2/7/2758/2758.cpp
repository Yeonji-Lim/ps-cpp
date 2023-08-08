#include <iostream>
#define M_N 12
#define M_M 4001

using namespace std;

int t,n,m;
long long dp[M_N][M_M];

int main() {
	cin >> t;
    for(int i = 1; i < M_M; i++) {
        dp[1][i] = 1;
    }
    for(int i = 2; i < M_N; i++) {
        for(int j = 2; j < M_M; j++) {
            dp[i][j] = dp[i][j-2] + dp[i-1][j/2];
        }
    }
    while(t--) {
        cin >> n >> m;
        cout << dp[n+1][m*2] << '\n';
    }
	return 0;
}