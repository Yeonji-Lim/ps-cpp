#include <bits/stdc++.h>
using namespace std;
int t, m, n;
char board[1001][1001];
int firedist[1001][1001];
int sangdist[1001][1001];
int d[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
bool isInMap(int i, int j) { return i > -1 && i < n && j > -1 && j < m; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> m >> n;
        pair<int, int> sang;
        queue<pair<int, int>> q;
        fill(&firedist[0][0], &firedist[n - 1][m - 1], -1);
        fill(&sangdist[0][0], &sangdist[n - 1][m - 1], 0);
        int ans = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> board[i][j];
                if (board[i][j] == '*') {
                    q.push({i, j});
                    firedist[i][j] = 0;
                }
                if (board[i][j] == '@') { 
                    sang = {i, j};
                }
            }
        }
        pair<int, int> cur;
        int ni, nj, dist;
        while(!q.empty()) {
            cur = q.front(); q.pop();
            dist = firedist[cur.first][cur.second];
            for(int k = 0; k < 4; k++) {
                ni = cur.first + d[k][0]; nj = cur.second + d[k][1];
                if (isInMap(ni, nj) && board[ni][nj] != '#' && firedist[ni][nj] == -1) {
                    firedist[ni][nj] = dist+1;
                    q.push({ni, nj});
                }
            }
        }
        q.push(sang);
        while(!q.empty()) {
            cur = q.front(); q.pop();
            dist = sangdist[cur.first][cur.second];
            for(int k = 0; k < 4; k++) {
                ni = cur.first + d[k][0]; nj = cur.second + d[k][1];
                if(!isInMap(ni, nj)) {
                    ans = dist+1;
                    break;
                }
                if(board[ni][nj] != '#' && (firedist[ni][nj] > dist + 1 || firedist[ni][nj] == -1)) {
                    sangdist[ni][nj] = dist+1;
                    q.push({ni, nj});
                }
            }
            if(ans != -1) break;
        }
        if(ans == -1) cout << "IMPOSSIBLE\n";
        else cout << ans << '\n';
    }
}