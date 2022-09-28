#include <bits/stdc++.h>
#define I first
#define J second
using namespace std;
int r, c;
char board[1002][1002];
int dist[1002][1002];
queue<pair<int, int>> jq;
queue<pair<int, int>> fq;
pair<int, int> curj;
pair<int, int> curf;

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
bool isInMap(int i, int j) { return i > -1 && i < r && j > -1 && j < c; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    string str;
    for(int i = 0; i < r; i++) {
        cin >> str;
        for(int j = 0; j < c; j++) {
            board[i][j] = str[j];
            if(board[i][j] == '#') dist[i][j] = -2;
            else if(board[i][j] == 'F') {
                dist[i][j] = -1;
                fq.push({i, j});
            } else if(board[i][j] == 'J') {
                dist[i][j] = 1;
                jq.push({i, j});
            } else {
                dist[i][j] = 0;
            }
        }
    }

    int ni, nj, d;
    bool imp = true;
    while(!jq.empty()) {
        curj = jq.front(); jq.pop();
        d = dist[curj.I][curj.J] ;

        if(!fq.empty()) {
            curf = fq.front(); fq.pop();
            for(int k = 0; k < 4; k++) {
                ni = curf.I + di[k]; nj = curf.J + dj[k];
                if(isInMap(ni, nj) && board[ni][nj] != 'F' && board[ni][nj] != '#') {
                    fq.push({ni, nj});
                    board[ni][nj] = 'F';
                }
            }
        }

        for(int k = 0; k < 4; k++) {
            ni = curj.I + di[k]; nj = curj.J + dj[k];
            if(!isInMap(ni, nj)) {
                cout << d << '\n';
                return 0;
            }
            if(isInMap(ni, nj) && board[ni][nj] != 'F' && board[ni][nj] != '#') {
                imp = false;
                jq.push({ni, nj});
                dist[ni][nj] = d+1;
            }
        }
        if(imp) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        imp = true;
    }
}
/**
 * @brief 
 * 같은 횟수에서 불이 먼저 퍼지게
 * 나오기 직전의 거리 값을 출력
 * imposible
 * -> 갈 곳이 없음 : 사방이 불
 */