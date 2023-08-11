#include <iostream>

using namespace std;

int n, m, ci, cj, cd, ni, nj, nd, ans = 0;
int board[50][50], d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool isInBoard(int i, int j) { return i > -1 && i < n && j > -1 && j < m; }
int getNextDirection(int x) { return (x == 0)? 3: x-1; }
int getBackDirection() { return getNextDirection(getNextDirection(cd)); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cin >> ci >> cj >> cd;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    
    bool cleaning;
    while(1) {
        cleaning = false;
        if(board[ci][cj] == 0) {
            ans++;
            board[ci][cj] = 2;
            continue;
        }
        for(int i = 0; i < 4; i++) {
            cd = getNextDirection(cd);
            ni = ci + d[cd][0]; nj = cj + d[cd][1];
            if(isInBoard(ni, nj) && board[ni][nj] == 0) {
                board[ni][nj] = 2;
                ci = ni; cj = nj;
                ans++;
                cleaning = true;
                break;
            }
        }
        if(cleaning) continue;
        nd = getBackDirection();
        ni = ci + d[nd][0]; nj = cj + d[nd][1];
        if(isInBoard(ni, nj) && board[ni][nj] != 1) {
            ci = ni; cj = nj;
            continue;
        }
        break;
    }
    cout << ans << '\n';

    return 0;
}