#include <bits/stdc++.h>
#define I first
#define J second
using namespace std;

int T, n, m, k, x, y, ans = 0;
bool board[51][51];
bool vis[51][51];

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
bool isInMap(int i, int j) { return i > -1 && i < n && j > -1 && j < m; }

void bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    pair<int, int> cur;
    int ni, nj;
    while(!q.empty()) {
        cur = q.front(); q.pop();
        for(int k = 0; k < 4; k++) {
            ni = cur.I + di[k]; nj = cur.J + dj[k];
            if(isInMap(ni, nj) && board[ni][nj] && !vis[ni][nj]) {
                vis[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--) {
        fill(&board[0][0], &board[50][50], false);
        fill(&vis[0][0], &vis[50][50], false);

        cin >> m >> n >> k;
        for(int i = 0; i < k; i++) {
            cin >> x >> y;
            board[y][x] = true;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] && !vis[i][j]) {
                    ans++;
                    bfs(i, j);
                }
            }
        }
        cout << ans << '\n';
        ans = 0;
    }
}