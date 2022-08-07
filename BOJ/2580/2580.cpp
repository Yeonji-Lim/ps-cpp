# include <bits/stdc++.h>
using namespace std;
int board[10][10];
bool rows[10][10];
bool cols[10][10];
bool square[10][10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    for(int row = 1; row < 10; row++) {
        for(int col = 1; col < 10; col++) {
            cin >> board[row][col];
            rows[row][board[row][col]] = true;
            cols[col][board[row][col]] = true;
            square[(row-1)/3*3+(col-1)/3+1][board[row][col]] = true;
        }
    }
    for(int row = 1; row < 10; row++) {
        for(int col = 1; col < 10; col++) {
            if(board[row][col] == 0) {
                for(int tar = 1; tar < 10; tar++){
                    if(!rows[row][tar] && !cols[col][tar] && !square[(row-1)/3*3+(col-1)/3+1][board[row][col]]) {
                        rows[row][tar] = true;
                        cols[col][tar] = true;
                        square[(row-1)/3*3+(col-1)/3+1][board[row][col]] = true;
                        board[row][col] = tar;
                    }
                }
            }
        }
    } 
    
}