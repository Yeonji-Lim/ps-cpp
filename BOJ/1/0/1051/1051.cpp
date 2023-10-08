#include <string>
#include <iostream>

using namespace std;
int n, m, ms, ans = 1;
int a, b, c, d;
int board[51][51];
string str;

bool isInBoard(int i, int j) { return i > -1 && i < n && j > -1 && j < m; }

void go(int ci, int cj) {
    int ni, nj;
    for(int k = ms; k > 0; k--) {
        ni = ci + k; nj = cj + k;
        if(isInBoard(ni,nj) && board[ci][cj] == board[ni][nj] && board[ci][cj] == board[ci][nj] && board[ci][cj] == board[ni][cj]) {            
            ans = max((k+1)*(k+1), ans);
        }
    }
}

int main() {
    cin >> n >> m;
    ms = min(n, m)-1;
    for(int i = 0; i < n; i++) {
        cin >> str;
        for(int j = 0; j < m; j++) {
            board[i][j] = str[j]-'0';
        }
    }
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < m-1; j++) {
            go(i, j);
        }
    }
    cout << ans << '\n';
    return 0;
}