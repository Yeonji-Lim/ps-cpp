#include <bits/stdc++.h>
using namespace std;

int n, l, r, ans = 0;
int world[50][50];
bool visited[50][50] = {false};
int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool isInMap(int i, int j) { return -1 < i && i < n && -1 < j && j < n; }

bool isUnion(int i1, int j1, int i2, int j2) {
    if(!isInMap(i2, j2) || visited[i2][j2]) return false;
    int sub = world[i1][j1] - world[i2][j2];
    if(sub < 0) sub *= -1;
    if(l <= sub && sub <= r) return true;
    return false;
}

bool makeUnion(int x, int y) {
    vector<pair<int, int>> u;
    queue<pair<int, int>> q;
    u.emplace_back(x, y);
    q.emplace(x, y);
    int tot = 0;
    while(!q.empty()){
        int ci = q.front().first, cj = q.front().second, ni, nj;
        tot += world[ci][cj];
        q.pop();

        for(int k = 0; k < 4; k++) {
            ni = ci+d[k][0]; nj = cj+d[k][1];
            if(isUnion(ci, cj, ni, nj)) {
                visited[ni][nj] = true;
                u.emplace_back(ni, nj);
                q.emplace(ni, nj);
            }
        }
    }
    if(u.size() == 1) {
        visited[x][y] = false;
        return false;
    }
    for(int i = 0; i < u.size(); i++) world[u[i].first][u[i].second] = tot/u.size();
    return true;
}

int main() {
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> world[i][j];
        }
    }
    bool done = true;
    while(1) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j]) {
                    visited[i][j] = true;
                    if(makeUnion(i, j)) done = false;
                }
            }
        }
        if(done) break;
        ans++;
        fill(&visited[0][0], &visited[n][n], false);
        done = true;
    }
    cout << ans << endl;
    return 0;
} 