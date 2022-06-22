#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, r, k, tmpans = 10000;
vector<vector<char>> map(100, vector<char>(100, '.'));
vector<vector<bool>> visited(100, vector<bool>(100, false));
vector<vector<int>> ansV; // (i, j, cnt)
int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
bool isInMap(int i, int j) { return -1 < i && i < n && -1 < j && j < m; }

int bfs(int si, int sj, int cnt, vector<vector<bool>> visited, int mode) {
    visited[si][sj] = true;
    int ret = 10000;
    if (cnt > tmpans) return ret;
    int ni, nj;
    for (int k = 0; k < 4; k++) {
        ni = si + d[k][0]; nj = sj + d[k][1];
        if (isInMap(ni, nj) && !visited[ni][nj]) {
            if (mode == 0 && map[ni][nj] == 'X') continue;
            if (mode == 3 && map[ni][nj] == 'S') {
                tmpans = cnt+1;
                return cnt+1;
            }
            if (map[ni][nj] == 'A' || map[ni][nj] == 'B' || map[ni][nj] == 'C') {
                vector<int> tmpV;
                tmpV.push_back(ni);
                tmpV.push_back(nj);
                tmpV.push_back(cnt+1);
                ansV.push_back(tmpV);
                tmpans = cnt+1;
                return cnt+1;
            }
            ret = min(ret, bfs(ni, nj, cnt+1, visited, mode));
            tmpans = ret;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    string input;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n >> m >> r >> k;
        for (int i = 0; i < n; i++) {
            cin >> input;
            for (int j = 0; j < m; j++) {
                map[i][j] = input[j];
            }
        }

        r--; k--;
        int ans = 0;
        for(int j = 0; j < 4; j++) {
            cout << "r = " << r << " k = " << k << endl;
            ans = bfs(r, k, ans, visited, j);
            cout << ans << endl;
            if(j == 3) break;
            for (int i = 0; i < ansV.size(); i++) {
                if (ansV[i][2] == ans) {
                    r = ansV[i][0];
                    k = ansV[i][1];
                    map[r][k] = '.';
                    break;
                }
            }
            fill(visited.begin(), visited.begin() + n, vector<bool>(m, false));
            ansV.clear();
            tmpans = 10000;
        }
        cout << "#" << t << " " << ans << endl;
    }
}
