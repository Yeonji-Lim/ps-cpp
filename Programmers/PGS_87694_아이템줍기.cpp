#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool isInBoard(int i, int j) { return i > -1 && i < 51 && j > -1 && j < 51; }

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    vector<vector<string>> board(51, vector<string>(51, "00000"));
    vector<vector<int>> dist(51, vector<int>(51, 0));
    for(vector<int> rec : rectangle) {
        int x1 = rec[0], y1 = rec[1], x2 = rec[2], y2 = rec[3];
        for(int i = x1; i <= x2; i++) {
            if(board[i][y1][0] != '2') board[i][y1][0] = '1';
            board[i][y1][2] = '1'; board[i][y1][4] = '1';
            if(board[i][y2][0] != '2') board[i][y2][0] = '1';
            board[i][y2][2] = '1'; board[i][y2][4] = '1';
        }
        for(int j = y1; j <= y2; j++) {
            if(board[x1][j][0] != '2') board[x1][j][0] = '1';
            board[x1][j][1] = '1'; board[x1][j][3] = '1';
            if(board[x2][j][0] != '2') board[x2][j][0] = '1';
            board[x2][j][1] = '1'; board[x2][j][3] = '1';
        }
        board[x1][y1][3] = '0'; board[x1][y1][4] = '0';
        board[x2][y1][2] = '0'; board[x2][y1][3] = '0';
        board[x1][y2][1] = '0'; board[x1][y2][4] = '0';
        board[x2][y2][1] = '0'; board[x2][y2][2] = '0';
        
        for(int i = x1+1; i < x2; i++)
            for(int j = y1+1; j < y2; j++)
                board[i][j][0] = '2';
    }
    for(int i = 1; i < 10; i++) {
        for(int j = 1; j < 10; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    queue<pair<int, int>> q;
    q.push({characterX, characterY});
    dist[characterX][characterY] = 0;
    int ci, cj, ni, nj, ndist;
    while(!q.empty()) {
        ci = q.front().first; cj = q.front().second;
        if(ci == itemX && cj == itemY) return dist[ci][cj];
        q.pop();
        ndist = dist[ci][cj]+1;
        for(int k = 0; k < 4; k++) {
            ni = ci + d[k][0]; nj = cj + d[k][1];
            if(isInBoard(ni, nj) && board[ni][nj][0] == '1' && board[ci][cj][k+1] == '1') {
                dist[ni][nj] = ndist;
                q.push({ni, nj});
            }
        }
    }
    return 0;
}