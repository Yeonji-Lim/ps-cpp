#include <bits/stdc++.h>
#define I first
#define J second
using namespace std;
int n, m, num = 0, ms = 0, cs;
int board[501][501];
bool visited[501][501];
queue<pair<int, int>> q;

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
bool isInMap(int i, int j) { return i > -1 && i < n && j > -1 && j < m; }

pair<int, int> cur;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            visited[i][j] = false;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] && !visited[i][j]) {
                num++; cs = 0;
                visited[i][j] = true;
                cur = {i, j};
                q.push(cur);
                while(!q.empty()) {
                    cur = q.front(); q.pop();
                    cs++;
                    for(int k = 0; k < 4; k++) {
                        int ni = cur.I + di[k], nj = cur.J + dj[k];
                        if(isInMap(ni, nj) && board[ni][nj] && !visited[ni][nj]) {
                            visited[ni][nj] = true;
                            q.push({ni, nj});
                        }
                    }
                }
                ms = cs > ms? cs: ms;
            }
        }
    }
    
    cout << num << '\n' << ms << '\n';
}