#include <bits/stdc++.h>
using namespace std;
int board[51][51];
int visited[51][51];
int n, m;
string str;
int direc[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool isInBoard(int i, int j) { return i > -1 && i < n && j > -1 && j < m; }

int go(int i, int j) {
    // 진행완료된 곳인 경우 반환
    if(visited[i][j] != 0) return visited[i][j];

    // 진행중 표시
    visited[i][j] = -1;
    int dist = board[i][j], ret = 0, ni, nj;
    // 상하좌우 진행
    for(int k = 0; k < 4; k++) {
        ni = i+direc[k][0]*dist; nj = j+direc[k][1]*dist;
        if(isInBoard(ni, nj) && board[ni][nj] != -1) { // 모두 못가는 위치면 ret == 0
            // 진행중인 곳이면 사이클 -> 무한대로
            if(visited[ni][nj] == -1) return visited[i][j] = INT_MAX;
            // 최대 길이 찾기
            ret = max(ret, go(ni, nj));
            // 내부에서 사이클 발생
            if(ret == INT_MAX) return visited[i][j] = INT_MAX;
        }
    }
    // 진행완료
    return visited[i][j] = ret+1;
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

    // visited : 방문 안함 - 0, 진행중 - -1, 처리완료 - 최종진행횟수
    // 상하좌우 간 것 중에 최대 
    // 무한인 경우 MAX를 넣고 출력할 때만 -1 출력

    int ans = go(0, 0);
    if(ans == INT_MAX) cout << "-1\n";
    else cout << ans << '\n';

    return 0;
}