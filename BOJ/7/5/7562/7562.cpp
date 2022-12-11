#include <bits/stdc++.h>
#define I first
#define J second
using namespace std;
int t, n, si, sj, ei, ej, ni, nj, dist, ans = 0;
int board[301][301];

int d[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
bool isInBoard(int i, int j) {return i > -1 && i < n && j > -1 && j < n; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> si >> sj >> ei >> ej;
        fill(&board[0][0], &board[n][n], 0);
        queue<pair<int, int>> q;
        pair<int, int> cur;
        q.push({si, sj});
        while(!q.empty()) {
            cur = q.front(); q.pop();
            dist = board[cur.I][cur.J];
            if(cur.I == ei && cur.J == ej) {
                ans = dist;
                break;
            }
            for(int k = 0; k < 8; k++) {
                ni = cur.I + d[k][0]; nj = cur.J + d[k][1];
                if(isInBoard(ni, nj) && board[ni][nj] == 0) {
                    board[ni][nj] = dist+1;
                    q.push({ni, nj});
                }
            }
        }
        cout << ans << '\n';
    }
}