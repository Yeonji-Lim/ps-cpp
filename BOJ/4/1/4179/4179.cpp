#include <bits/stdc++.h>
#define I first
#define J second
using namespace std;
int r, c;
char board[1002][1002];
int dist[1002][1002];
queue<pair<int, int>> jq;
queue<pair<int, int>> fq;
queue<pair<int, int>> fq1;
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
            if(board[i][j] == 'F') {
                fq.push({i, j});
            } else if(board[i][j] == 'J') {
                dist[i][j] = 1;
                jq.push({ i, j});
            } else {
                dist[i][j] = 0;
            }
        }
    }

    int ni, nj, d;
    bool imp = true, fcur = true;
    while(!jq.empty()) {
        curj = jq.front(); jq.pop();
        d = dist[curj.I][curj.J];
        
        if(fcur) {
            if(!fq.empty()) {
                curf = fq.front(); fq.pop();
                for(int k = 0; k < 4; k++) {
                    ni = curf.I + di[k]; nj = curf.J + dj[k];
                    if(isInMap(ni, nj) && board[ni][nj] == '.') {
                        fq1.push({ni, nj});
                        board[ni][nj] = 'F';
                    }
                }
            }
        } else {
            if(!fq1.empty()) {
                curf = fq1.front(); fq1.pop();
                for(int k = 0; k < 4; k++) {
                    ni = curf.I + di[k]; nj = curf.J + dj[k];
                    if(isInMap(ni, nj) && board[ni][nj] == '.') {
                        fq.push({ni, nj});
                        board[ni][nj] = 'F';
                    }
                }
            }
        }
        fcur != fcur;

        for(int k = 0; k < 4; k++) {
            ni = curj.I + di[k]; nj = curj.J + dj[k];
            if(!isInMap(ni, nj)) {
                cout << d << '\n';
                return 0;
            }
            if(isInMap(ni, nj) && board[ni][nj] == '.' && dist[ni][nj] == 0) {
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