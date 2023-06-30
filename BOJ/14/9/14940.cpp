#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> board, res;
queue<pair<int, int>> q;
pair<int, int> tp;
int n, m, ci, cj, ni, nj, dist;

int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
bool isInBoard(int i, int j) { return i > -1 && i < n && j > -1 && j < m; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    board.resize(n, vector<int>(m, 0));
    res.resize(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2) q.emplace(i, j);
        }
    }

    while(!q.empty()) {
        tp = q.front(); q.pop();
        ci = tp.first; cj = tp.second;

        for(int k = 0; k < 4; k++) {
            ni = ci + d[k][0]; nj = cj + d[k][1];
            dist = res[ci][cj] + 1;
            if(isInBoard(ni, nj) && board[ni][nj] && !res[ni][nj]) {
                res[ni][nj] = dist;
                q.emplace(ni, nj);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}