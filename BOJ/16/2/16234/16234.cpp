// #include <bits/stdc++.h>
// using namespace std;

// int n, l, r, ans = 0;
// int world[50][50];
// bool visited[50][50] = {false};
// int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
// bool isInMap(int i, int j) { return -1 < i && i < n && -1 < j && j < n; }

// bool isUnion(int i1, int j1, int i2, int j2) {
//     if(!isInMap(i2, j2) || visited[i2][j2]) return false;
//     int sub = world[i1][j1] - world[i2][j2];
//     if(sub < 0) sub *= -1;
//     if(l <= sub && sub <= r) return true;
//     return false;
// }

// bool makeUnion(int x, int y) {
//     vector<pair<int, int>> u;
//     queue<pair<int, int>> q;
//     u.emplace_back(x, y);
//     q.emplace(x, y);
//     int tot = 0;
//     while(!q.empty()){
//         int ci = q.front().first, cj = q.front().second, ni, nj;
//         tot += world[ci][cj];
//         q.pop();

//         for(int k = 0; k < 4; k++) {
//             ni = ci+d[k][0]; nj = cj+d[k][1];
//             if(isUnion(ci, cj, ni, nj)) {
//                 visited[ni][nj] = true;
//                 u.emplace_back(ni, nj);
//                 q.emplace(ni, nj);
//             }
//         }
//     }
//     if(u.size() == 1) {
//         visited[x][y] = false;
//         return false;
//     }
//     for(int i = 0; i < u.size(); i++) world[u[i].first][u[i].second] = tot/u.size();
//     return true;
// }

// int main() {
//     cin >> n >> l >> r;
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n; j++) {
//             cin >> world[i][j];
//         }
//     }
//     bool done = true;
//     while(1) {
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < n; j++) {
//                 if(!visited[i][j]) {
//                     visited[i][j] = true;
//                     if(makeUnion(i, j)) done = false;
//                 }
//             }
//         }
//         if(done) break;
//         ans++;
//         fill(&visited[0][0], &visited[n][n], false);
//         done = true;
//     }
//     cout << ans << endl;
//     return 0;
// } 

// #include <bits/stdc++.h>
// using namespace std;
// int n, l, r;
// vector<vector<int>> globalMap(50, vector<int>(50, 0));
// vector<vector<bool>> visited(50, vector<bool>(50, false));
// vector<vector<pair<int, int>>> unions;
// int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
// bool isInMap(int i, int j) { return i > -1 && i < n && j > -1 && j < n; }
// bool isUnionPossible(int ci, int cj, int ni, int nj) {
//     int sub = max(globalMap[ci][cj], globalMap[ni][nj]) - min(globalMap[ci][cj], globalMap[ni][nj]);
//     return l <= sub && sub <= r;
// }

// vector<pair<int, int>> migration(int i, int j) {
//     vector<pair<int, int>> unionCountrys;
//     queue<pair<int, int>> q;

//     visited[i][j] = true;
//     unionCountrys.emplace_back(i, j);
//     q.emplace(i, j);

//     while(!q.empty()) {
//         int ci = q.front().first, cj = q.front().second;
//         q.pop();
//         for(int k = 0; k < 4; k++) {
//             int ni = ci+d[k][0], nj = cj+d[k][1];
//             if(isInMap(ni,nj) && !visited[ni][nj] && isUnionPossible(ci, cj, ni, nj)) {
//                 visited[ni][nj] = true;
//                 unionCountrys.emplace_back(ni, nj);
//                 q.emplace(ni, nj);
//             }
//         }
//     }

//     return unionCountrys;
// }

// void seperatePeople(vector<pair<int, int>> unionCountrys) {
//     int size = (int)unionCountrys.size(), tmp = 0;
//     for(int i = 0; i < size; i++)
//         tmp += globalMap[unionCountrys[i].first][unionCountrys[i].second];
//     tmp /= size;
//     for(int i = 0; i < size; i++)
//         globalMap[unionCountrys[i].first][unionCountrys[i].second] = tmp;
// }

// int main() {
//     cin >> n >> l >> r;
//     for(int i = 0; i < n; i++)
//         for(int j = 0; j < n; j++)
//             cin >> globalMap[i][j];
//     int cnt = 1, ans = 0;
//     do {
//         cnt = 1;
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < n; j++) {
//                 if(!visited[i][j]) {
//                     vector<pair<int, int>> unionCountrys = migration(i, j);
//                     cnt = max(cnt, (int)unionCountrys.size());
//                     unions.push_back(unionCountrys);
//                 }
//             }
//         }
//         if(cnt == 1) break;
//         for(int i = 0; i < (int)unions.size(); i++)
//             seperatePeople(unions[i]);
//         fill(visited.begin(), visited.end(), vector<bool>(50, false));
//         unions.clear();
//         ans++;
//     } while(cnt > 1);
//     cout << ans << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, l, r, cnt = 0;
int board[50][50];

vector<vector<pair<int, int>>> ucs;
queue<pair<int, int>> q;

int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool isInBoard(int i, int j) { return i > -1 && i < n && j > -1 && j < n; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> r;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    do {
        ucs.clear();
        bool vis[50][50] = {false, };
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j]) {
                    vis[i][j] = true;
                    q.emplace(i, j);
                    vector<pair<int, int>> uc;
                    uc.emplace_back(i, j);
                    int ci, cj, ni, nj, dist, total = board[i][j];

                    while(!q.empty()) {
                        ci = q.front().first; cj = q.front().second;
                        q.pop();
                        for(int k = 0; k < 4; k++) {
                            ni = ci + d[k][0]; nj = cj + d[k][1];
                            if(isInBoard(ni, nj) && !vis[ni][nj]) {
                                dist = abs(board[ci][cj]-board[ni][nj]);
                                if(dist >= l && dist <= r) {
                                    vis[ni][nj] = true;
                                    q.emplace(ni, nj);
                                    uc.emplace_back(ni, nj);
                                    total += board[ni][nj];
                                }
                            }
                        }
                    }
                    if(uc.size() == 1) {
                        vis[i][j] = false;
                        continue;
                    }
                    uc.emplace_back(total, uc.size());
                    ucs.push_back(uc);
                }
            }
        }
        if(ucs.empty()) break;
        vector<pair<int, int>> uc;
        int cal;
        for(int i = 0; i < ucs.size(); i++) {
            uc = ucs[i];
            cal = uc[uc.size()-1].first / uc[uc.size()-1].second;
            for(int j = 0; j < uc.size()-1; j++) {
                board[uc[j].first][uc[j].second] = cal;
            }
        }
        cnt++;
    } while(!ucs.empty());

    cout << cnt << '\n';
    return 0;
}