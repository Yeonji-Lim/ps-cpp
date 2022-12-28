#include <bits/stdc++.h>
#define MS 1001
#define I first
#define J second
using namespace std;
int n, m;

int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int isInMap(int i, int j) { return i > -1 && i < n && j > -1 && j < m; }

int go(queue<pair<int, int>> q, int board[][], bool canbreak) {
    pair<int, int> cur;
    int ni, nj, dist, ret = -1;
    while(!q.empty()) {
        cur = q.front(); q.pop();
        dist = board[cur.I][cur.J];
        for(int k = 0; k < 4; k++) {
            ni = cur.I + d[k][0]; nj = cur.J + d[k][1];
            if(isInMap(ni, nj)) {
                if(canbreak && board[ni][nj] == -1) {
                    int tmp = go(q, board, !canbreak);
                    if (tmp != -1) ret = min(ret, tmp);
                }
                if(board[ni][nj] == 0) {
                    board[ni][nj] = dist + 1;
                    q.push({ni, nj});
                }
            }
        }
    }
    if(board[n-1][m-1] != 0)
        ret = min(ret, board[n-1][m-1]);
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int board[MS][MS];
    for(int i = 0; i < n; i++ ) {
        for (int j = 0; j < m; j++ ) {
            cin >> board[i][j];
            if (board[i][j] == 1) board[i][j] = -1;
        }
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    cout << go(q, board, true);
}