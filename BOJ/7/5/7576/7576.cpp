#include <bits/stdc++.h>
#define I first
#define J second
using namespace std;
int n, m, ans = 0;
int box[1001][1001];
queue<pair<int, int>> q1;
queue<pair<int, int>> q2;
bool qp = true;

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
bool isInMap(int i, int j) { return i > -1 && i < n && j > -1 && j < m; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> box[i][j];
            if(box[i][j] == 1) q1.push({i, j});
        }
    }
    pair<int, int> cur;
    while(!q1.empty() || !q2.empty()) {
        if(qp) {
            while(!q1.empty()) {
                cur = q1.front(); q1.pop();
                for(int k = 0; k < 4; k++) {
                    int ni = cur.I + di[k], nj = cur.J + dj[k];
                    if(isInMap(ni, nj) && box[ni][nj] == 0) {
                        box[ni][nj] = 1;
                        q2.push({ni, nj});
                    }
                }
            }
        } else {
            while(!q2.empty()) {
                cur = q2.front(); q2.pop();
                for(int k = 0; k < 4; k++) {
                    int ni = cur.I + di[k], nj = cur.J + dj[k];
                    if(isInMap(ni, nj) && box[ni][nj] == 0) {
                        box[ni][nj] = 1;
                        q1.push({ni, nj});
                    }
                }
            }
        }
        qp = !qp;
        ans++;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(box[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << ans-1 << '\n';
}

/**
 * @brief 
 * 직사각형일 때 막힌걸 인식을 못함
 * -> n과 m의 입력 순서가 뒤바뀌어 있었음
 */