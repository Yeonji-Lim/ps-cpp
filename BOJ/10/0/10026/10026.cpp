#include <bits/stdc++.h>
#define I first
#define J second
using namespace std;
int n, ans = 0, weakans = 0;
string str;
char board[101][101];
bool vis[101][101];

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
bool isInMap(int i, int j) { return i > -1 && i < n && j > -1 && j < n; }

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    vis[i][j] = true;
    q.push({i, j});
    pair<int, int> cur;
    int ni, nj;
    while(!q.empty()) {
        cur = q.front(); q.pop();
        for(int k = 0; k < 4; k++) {
            ni = cur.I + di[k]; nj = cur.J + dj[k];
            if(isInMap(ni, nj) && !vis[ni][nj] && board[i][j] == board[ni][nj]) {
                vis[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }
}

void weakbfs(int i, int j) {
    queue<pair<int, int>> q;
    vis[i][j] = true;
    q.push({i, j});
    pair<int, int> cur;
    int ni, nj;
    while(!q.empty()) {
        cur = q.front(); q.pop();
        for(int k = 0; k < 4; k++) {
            ni = cur.I + di[k]; nj = cur.J + dj[k];
            if(isInMap(ni, nj) && !vis[ni][nj] && board[ni][nj] != 'B') {
                vis[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    fill(&vis[0][0], &vis[n][n], false);
    for(int i = 0; i < n; i++) {
        cin >> str;
        for(int j = 0; j < n; j++) {
            board[i][j] = str[j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!vis[i][j]) {
                ans++;
                if(board[i][j] == 'B') weakans++;
                bfs(i, j);
            }
        }
    }

    if(weakans != 0) {
        fill(&vis[0][0], &vis[n][n], false);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && board[i][j] != 'B') {
                    weakans++;
                    weakbfs(i, j);
                }
            }
        }
    } else weakans = 1;
    cout << ans << ' ' << weakans << '\n';
}

/**
 * @brief 
 * B인 경우의 개수를 미리 저장해두기 weakans에
 * 그러고 나서 G, R에 대해서 다시 bfs 진행
 */