#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, r, k, tmpans = 10000;
vector<vector<char>> map(100, vector<char>(100, '.'));
vector<vector<bool>> visited(100, vector<bool>(100, false));
vector<vector<int>> gof(100, vector<int>(100, 10000));

vector<vector<int>> open;
vector<pair<int, int>> excalibur;
vector<int> dist;
pair<int, int> S;
int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
bool isInMap(int i, int j) { return -1 < i && i < n && -1 < j && j < m; }
int h(int i, int j, pair<int, int> t) { return max(t.first, i)-min(t.first, i)+max(t.second, j)-min(t.second, j); }

int aStar(int si, int sj, pair<int, int> target, int g, int mode) {
    visited[si][sj];
    int min = 10000, ni, nj, f, mi, mj;
    // 상하좌우 중 가장 f가 작은 곳 선택
    for(int k = 0; k < 4; k++) {
        ni = si+d[k][0]; nj = sj+d[k][1];
        if(isInMap(ni, nj)) {
            // 이미 도착지인 경우
            if(ni==target.first && nj == target.second) return g+1;
            // 산인 경우 : 아무것도 못찾은 경우에만 통과 가능
            if(mode == 0 && map[ni][nj] == 'X') continue;
            // 가장 f가 작은 거 선택
            f = g + h(ni, nj, target);
            open.emplace_back(f, ni, nj);
            sort(open.begin(), open.end());
        }
    }
    for(int k = 0; k < open.size(); k++) {
        int ret = aStar(open[0][1], open[0][2], target, open[0][0] - h(open[0][1], open[0][2], target), mode);
        if(ret != 10000)
    }
    // if(min == 10000) return min;
    // return aStar(mi, mj, target, g+1);
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
                if(input[j] == 'A' || input[j] == 'B' || input[j] == 'C') excalibur.emplace_back(i, j);
                if(input[j] == 'S') S = make_pair(i, j);
            }
        }
        int ans = 0;
        for(int i= 0; i < 4; i++) {
            if(excalibur.empty()) {
                break;
            }
            for(int j = 0; j < excalibur.size(); j++) {
                dist.push_back
            }
        }
        
        cout << "#" << t << " " << ans << endl;
    }
}
