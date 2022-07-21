#include <bits/stdc++.h>
#define MAX 3600
using namespace std;
// vector<vector<int>> board(50, vector<int>(50, 0));
int board[51][51];
int visited[51][51];
int n, m;
string str;
int direc[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool isInBoard(int i, int j) { return i > -1 && i < n && j > -1 && j < m; }

int go(int i, int j) {
    visited[i][j] = 1;
    int dist = board[i][j];
    if(dist == -1) return 0;
    // 상하좌우 진행
    int ret = 0, ni, nj;
    for(int k = 0; k < 4; k++) {
        ni = i+direc[k][0]*dist; nj = j+direc[k][1]*dist;
        if(isInBoard(ni, nj)) { // 모두 못가는 위치면 ret == 0
            if(visited[ni][nj] == 1) return MAX;
            ret = max(ret, go(ni, nj));
            if(ret == MAX) return MAX;
        }
    }
    visited[i][j] = 2;
    return ret+1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> str;
        for(int j = 0; j < m ; j++) {
            board[i][j] = str[j]=='H'? -1: str[j]-'0';
        }
    }

    // visited : 방문 안함 - 0, 진행중 - 1, 처리완료 - 2
    // 상하좌우 간 것 중에 최대 
    // 무한인 경우 MAX를 넣고 출력할 때만 -1 출력

    int ans = go(0, 0);
    if(ans == MAX) cout << "-1\n";
    else cout << ans << '\n';

    return 0;
}