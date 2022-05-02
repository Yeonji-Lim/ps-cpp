#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> map(8, vector<int>(8, -1));
int di[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

vector<vector<int>> placementWall(int loc[][2]) {
    vector<vector<int>> newMap(8, vector<int>(8, -1));
    copy(map.begin(), map.end(), newMap.begin());
    for(int i = 0; i < 0; i++) {
        newMap[loc[i][0]][loc[i][1]] = 1;
    }
    return newMap;
}

void virusAttack(vector<vector<int>> targetMap) {
    bool visited[8][8];
    for(int i = 0; i < N; i++) { for(int j = 0; j < M; j++) {
        if(targetMap[i][j] == 2 && !visited[i][j]) {
            visited[i][j] = true;
            queue<pair<int, int>> q;
            q.push(make_pair(i, j));

            while(!q.empty()) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int k = 0; k < 4; k++) {
                    int nx = x + di[k][0], ny = y + di[k][1];
                    if(targetMap[nx][ny] == 0) {
                        targetMap[nx][ny] = 2;
                        visited[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }}
}

int countSafe(vector<vector<int>> targetMap) {
    int ret = 0;
    virusAttack(targetMap);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(targetMap[i][j] == 0) {
                ret++;
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<pair<int, int>> candidates;
    int ans = 0;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            if(map[i][j] == 0) candidates.emplace_back(i, j);
        }
    }
    vector<bool> perm(candidates.size(), false);
    fill(perm.end()-3, perm.end(), true);
    int targets[3][2];
    do {
        int j = 0;
        for(int i = 0; i < perm.size(); i++) {
            if(j == 3) break;
            if(perm[i]){
                targets[j][0] = candidates[perm[i]].first;
                targets[j][1] = candidates[perm[i]].second;
                j++;
            }
        }
        ans = max( countSafe(placementWall(targets)), ans );
    } while( next_permutation(perm.begin(), perm.end()) );
    cout << ans << endl;
    return 0;
}