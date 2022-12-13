#include <bits/stdc++.h>
using namespace std;
int t, m, n;
char board[1001][1001];
int firedist[1001][1001];
int d[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
bool isInMap(int i, int j) { return i > -1 && i < n && j > -1 && j < m; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> m >> n;
        queue<pair<int, int>> q;
        queue<pair<int, int>> q1;
        fill(&firedist[0][0], &firedist[n - 1][m - 1], -1);
        int ans = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> board[i][j];
                if (board[i][j] == '*') {
                    q.push({i, j});
                    firedist[i][j] = 0;
                }
                if (board[i][j] == '@') { // 이렇게 하는 방법 보다 좋은 방법이 있엇던 것 같다.
                    q1.push({i, j});
                }
            }
        }
        pair<int, int> cur;
        int ni, nj, dist, flag = 0;
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
        // 상근이의 dist 보다 firedist가 커야 함 같아도 안됨
        dist = 0;
        while(ans == -1) {
            if(flag == 0) {
                while(!q1.empty()) {
                    cur = q1.front(); q1.pop();
                    for(int k = 0; k < 4; k++) {
                        ni = cur.first + d[k][0]; nj = cur.second + d[k][1];
                        if(!isInMap(ni, nj)) {
                            ans = dist+1;
                            break;
                        }
                        if(board[ni][nj] != '#' && (firedist[ni][nj] > dist + 1 || firedist[ni][nj] == -1)) {
                            q.push({ni, nj});
                        }
                    }
                    if(ans != -1) break;
                }
            } else {
                while(!q.empty()) {
                    cur = q.front(); q.pop();
                    for(int k = 0; k < 4; k++) {
                        ni = cur.first + d[k][0]; nj = cur.second + d[k][1];
                        if(!isInMap(ni, nj)) {
                            ans = dist+1;
                            break;
                        }
                        if(board[ni][nj] != '#' && (firedist[ni][nj] > dist + 1 || firedist[ni][nj] == -1)) {
                            q1.push({ni, nj});
                        }
                    }
                    if(ans != -1) break;
                }
            }
            flag = (flag+1)%2;
            dist++;
            if(q.empty() && q1.empty()) break;
        }
        
        if(ans == -1) cout << "IMPOSSIBLE\n";
        else cout << ans << '\n';
    }
}