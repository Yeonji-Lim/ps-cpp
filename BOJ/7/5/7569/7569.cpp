#include <bits/stdc++.h>
using namespace std;
int m, n, h;
int box[10][10][10];
int d[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 0, -1}, {0, 0, 1}, {0, -1, 0}, {0, 1, 0}};
bool isInBox(int k, int i, int j) { return k > -1 && k < h && i > -1 && i < n && j > -1 && j < m; }
queue<vector<int>> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> h;
    for(int k = 0; k < h; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> box[k][i][j];
                if(box[k][i][j] == 1) {
                    q.push({k, i, j});
                }
            }
        }
    }
    
vector<int> cur;
    int dist, nk, ni, nj;
    while(!q.empty()) {
        cur = q.front(); q.pop();
        dist = box[cur[0]][cur[1]][cur[2]];
        for(int a = 0; a < 6; a++) {
            nk = cur[0] + d[a][0]; ni = cur[1] + d[a][1]; nj = cur[2] + d[a][2];
            if(isInBox(nk, ni, nj) && box[nk][ni][nj] == 0) {
                box[nk][ni][nj] = dist+1;
                q.push({nk, ni, nj});
            }
        }
    }
    
    dist--;
    if (dist != 0) {
        for(int k = 0; k < h; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(box[k][i][j] == 0) {
                        dist = -1;
                        break;
                    }
                }
                if(dist == -1) break;
            }
            if(dist == -1) break;
        }
    }
    cout << dist << '\n';
}