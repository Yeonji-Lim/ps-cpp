# include <bits/stdc++.h>
using namespace std;
int board[9][9];
bool rows[9][10]; // 숫자는 1 ~ 9로 표시
bool cols[9][10];
bool square[9][10];

void DFS(int cnt) {
    if(cnt == 81) {
        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {
                cout << board[row][col] << " ";
            }
            cout << '\n';
        }
        exit(0);
    }
    int row = cnt/9;
    int col = cnt%9;
    if(board[row][col] == 0) {
        for(int tar = 1; tar < 10; tar++){
            if(!rows[row][tar] && !cols[col][tar] && !square[row/3*3+col/3][tar]) {
                rows[row][tar] = true;
                cols[col][tar] = true;
                square[row/3*3+col/3][tar] = true;
                board[row][col] = tar;
                DFS(cnt+1);
                board[row][col] = 0;
                rows[row][tar] = false;
                cols[col][tar] = false;
                square[row/3*3+col/3][tar] = false;
            }
        }
    } else {
        DFS(cnt+1);
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    for(int row = 0; row < 9; row++) {
        for(int col = 0; col < 9; col++) {
            cin >> board[row][col];
            // 각 row, col, square에 그 숫자가 있음을 표시
            rows[row][board[row][col]] = true;
            cols[col][board[row][col]] = true;
            square[row/3*3+col/3][board[row][col]] = true;
        }
    }
    DFS(0);
}