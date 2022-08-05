# include <bits/stdc++.h>
using namespace std;
int board [10][10];
int pos_info [10][10];
queue<int> numq [10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int tar, row, col;
    for(row = 1; row < 10; row++) {
        for(col = 1; col < 10; col++) {
            cin >> board[row][col];
            pos_info[board[row][col]][col] = row;
        }
    }
    
    for(tar = 1; tar < 10; tar++) {
        queue<int> remain_rows;
        for(row = 1; row < 10; row++) {
            for(col = 1; col < 10; col++) {
                if(pos_info[tar][col] == row) break;
            }
            if(col != 10) continue;
            remain_rows.push(row);
        }
        for(col = 1; col < 10; col++) {
            if(pos_info[tar][col] == 0) {
                int first_row = queue.top();
                int remain_row = queue.top();
                do {
                    queue.pop();
                    // 사각형 내부 맞는지 확인, 맞으면 적고 break

                    queue.push(remain_row);
                    remain_row = queue.top();
                } while(remain_row != first_row);
            }
        }
    }
    
    
    for(int i = 1; i < 10; i++) {
        for(int j = 1; j < 10; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}