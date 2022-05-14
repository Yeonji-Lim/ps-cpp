#include <bits/stdc++.h>
using namespace std;

int n, l, r, ans = 0;
int world[50][50];
bool visited[50][50] = {false};
bool isInMap(int i, int j) { return -1 < i && i < n && -1 < j && j < n; }

bool isUnion(int i1, int j1, int i2, int j2) {
    if(!isInMap(i2, j2)) return false;
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
    while(!q.empty()){
        int ci = q.front().first, cj = q.front().second;
        q.pop();
        if(isUnion(ci, cj, ci, cj+1)) {
            visited[ci][cj+1] = true;
            u.emplace_back(ci, cj+1);
            q.emplace(ci, cj+1);
        }
        if(isUnion(ci, cj, ci+1, cj)) {
            visited[ci+1][cj] = true;
            u.emplace_back(ci+1, cj);
            q.emplace(ci+1, cj);
        }
    }
    if(u.size() == 1) return false;
    // 값 변경
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
    }
    cout << ans << endl;
    return 0;
} 