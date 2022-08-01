# include <bits/stdc++.h>
using namespace std;
int board [10][10];
int pos_info [10][10];
queue<int> numq [10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    for(int i = 1; i < 10; i++) {
        for(int j = 1; j < 10; j++) {
            cin >> board[i][j];
            pos_info[board[i][j]][j] = i;
        }
    }
    
}