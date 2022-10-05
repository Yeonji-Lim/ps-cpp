#include <bits/stdc++.h>
#define I first
#define J second
using namespace std;
int r, c, d, ni, nj;
pair<int, int> cur;
pair<int, int> jihun;
queue<pair<int, int>> q;

char board[1002][1002];
int distf[1002][1002];
int distj[1002][1002];

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
bool isInMap(int i, int j) { return i > -1 && i < r && j > -1 && j < c; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    string str;
    for(int i = 0; i < r; i++) {
        cin >> str;
        for(int j = 0; j < c; j++) {
            board[i][j] = str[j];
            distf[i][j] = -1;
            distj[i][j] = -1;
            if(board[i][j] == 'F') {
                q.push({i, j});
                distf[i][j] = 0;
            } else if(board[i][j] == 'J') {
                jihun = {i, j};
                distj[i][j] = 0;
            }
        }
    }
    while(!q.empty()) {
        cur = q.front(); q.pop();
        d = distf[cur.I][cur.J];
        for(int k = 0; k < 4; k++) {
            ni = cur.I + di[k]; nj = cur.J + dj[k];
            if(isInMap(ni, nj) && board[ni][nj] != '#' && distf[ni][nj] == -1) {
                distf[ni][nj] = d+1;
                q.push({ni, nj});
            }
        }
    }

    q.push(jihun);
    while(!q.empty()) {
        cur = q.front(); q.pop();
        d = distj[cur.I][cur.J];
        for(int k = 0; k < 4; k++) {
            ni = cur.I + di[k]; nj = cur.J + dj[k];
            if(!isInMap(ni, nj)) {
                cout << d+1 << '\n';
                return 0;
            }
            if(board[ni][nj] == '.' && distj[ni][nj] == -1 && (distj[ni][nj] > d+1 || distf[ni][nj] == -1)) {
                distj[ni][nj] = d+1;
                q.push({ni, nj});
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}