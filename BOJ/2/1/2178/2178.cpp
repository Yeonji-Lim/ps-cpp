#include <bits/stdc++.h>
#define I first
#define J second
using namespace std;
int n, m;
string str;
int board[101][101];
bool vis[101][101];
queue<pair<int, int>> q;

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
bool isInMap(int i, int j) { return i > -1 && i < n && j > -1 && j < m; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> str;
        for(int j = 0; j < m; j++) {
            if(str[j] == '0') board[i][j] = -1;
            else board[i][j] = 0;
            vis[i][j] = false;
        }
    }

    q.push({0, 0});
    board[0][0] = 1;
    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for(int k = 0; k < 4; k++) {
            int ni = cur.I + di[k], nj = cur.J + dj[k];
            if(isInMap(ni, nj) && board[ni][nj] != -1 && !vis[ni][nj]) {
                vis[ni][nj] = true;
                board[ni][nj] = board[cur.I][cur.J]+1;
                q.push({ni, nj});
            }
        }
    }

    cout << board[n-1][m-1] << '\n';
}

/**
 * @brief 
 * 의문점
 * 최소임을 보장하지 않아도 항상 나오는 값은 최소인가?
 * 
 */