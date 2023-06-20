#include <iostream>
#define MS 501

using namespace std;

int board[MS][MS];
int dp[MS][MS];
int n, m, ans = 0;

bool isInBoard(int i, int j) { return i > -1 && i < n && j > -1 && j < m; }
int d[4][2] = { {1, 0}, {0, 1}, {0, -1}, {-1, 0} };

int dfs(int i, int j) { 
    if(dp[i][j] != -1) return dp[i][j];

    int ni, nj;
    dp[i][j] = 0;
    for(int k = 0; k < 4; k++) {
        ni = i + d[k][0]; nj = j + d[k][1];
        if(isInBoard(ni, nj) && board[i][j] > board[ni][nj])
            dp[i][j] += dfs(ni, nj);
    }
    return dp[i][j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    fill(&dp[0][0], &dp[n][m], -1);
    dp[n-1][m-1] = 1;
    dfs(0, 0);
    cout << dp[0][0] << '\n';
    return 0;
}