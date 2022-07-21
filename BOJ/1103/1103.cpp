#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> board(50, vector<int>(50, 0));
vector<vector<int>> visited(50, vector<int>(50, -1));
int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
bool isInMap(int i, int j) { return i > -1 && i < n && j > -1 && j < m; }
bool isInHole(int i, int j) { return board[i][j] == 'H'; } 
stack<pair<int, int>> st;

int move(int ci, int cj) {
    int ans = 0;
    for(int k = 0; k < 4; k++) {
        int ni = ci+d[k][0]*board[ci][cj], nj = ci+d[k][1]*board[ci][cj], tmp = 0;
        if(!isInMap(ni, nj)) continue;
        if(isInHole(ni, nj)) continue;
        tmp = visited[ni][nj];
        if(tmp != 0) { ans = -1; break; }
        tmp = move(ni, nj);
        if(ans < tmp) ans = tmp;
    }
    if(ans != -1) ans++;
    visited[ci][cj] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    // st.emplace(0, 0);
    // while(!st.empty()) {
    //     int ci = st.top().first, cj = st.top().second;
    //     st.pop();
    //     for(int k = 0; k < 4; k++) {
    //         int ni = ci+d[k][0]*board[ci][cj], nj = ci+d[k][1]*board[ci][cj];
    //         if(!isInMap(ni, nj)) continue;
    //         if(isInHole(ni, nj)) continue;
    //         if(visited[ni][nj] == 1) {}
    //         st.emplace(ni, nj);
    //         visited[ci][cj] = 2;
    //     }
    //     if(visited[ci][cj] == 0) visited[ci][cj] = 1;
    // }
    cout << move(0, 0) << endl;
    return 0;
}