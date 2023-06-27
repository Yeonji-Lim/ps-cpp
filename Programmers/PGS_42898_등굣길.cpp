#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;

int m, n, ans = 0;
vector<vector<bool>> board; // 잠김 여부
vector<vector<int>> dp; // 목적지까지 갈 수 있는 경로의 수

int d[2][2] = {{0, 1}, {1, 0}};
bool isInBoard(int i, int j) { return i > -1 && i < n && j > -1 && j < m; }

int dfs(int ci, int cj) {
    if(dp[ci][cj] > 0) return dp[ci][cj];
    
    int ni, nj;
    for(int k = 0; k < 2; k++) {
        ni = ci + d[k][0]; nj = cj + d[k][1];
        if(isInBoard(ni, nj) && board[ni][nj]) {
            dp[ci][cj] += dfs(ni, nj);
            dp[ci][cj] %= MOD;
        }
    }
    return dp[ci][cj];
}

int solution(int im, int in, vector<vector<int>> puddles) {
    m = im;
    n = in;
    board.resize(n, vector<bool>(m, true));
    dp.resize(n, vector<int>(m, 0));
    for(int i = 0; i < puddles.size(); i++) {
        board[puddles[i][1]-1][puddles[i][0]-1] = false;
    }
    dp[n-1][m-1] = 1;
    dfs(0, 0);
    return dp[0][0];
}