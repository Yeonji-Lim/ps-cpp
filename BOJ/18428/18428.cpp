// #include <bits/stdc++.h>
// using namespace std;
// int n;
// char cor[6][6];
// vector<pair<int, int>> teacher;
// vector<pair<int, int>> student;
// vector<pair<int, int>> space;
// bool ans = false;

// bool isAvoidWatch() {
//     bool ret = true;
//     for(int t = 0; t < teacher.size(); t++) {
//         int ti = teacher[t].first, tj = teacher[t].second;
//         int i = ti, j;
//         for(j = tj-1; j > -1; j--) {
//             if(cor[i][j] == 'O') break;
//             if(cor[i][j] == 'S') return false;
//         }
//         for(j = tj+1; j < n; j++) {
//             if(cor[i][j] == 'O') break;
//             if(cor[i][j] == 'S') return false;
//         }
//         j = tj;
//         for(i = ti-1; i > -1; i--) {
//             if(cor[i][j] == 'O') break;
//             if(cor[i][j] == 'S') return false;
//         }
//         for(i = ti+1; i < n; i++) {
//             if(cor[i][j] == 'O') break;
//             if(cor[i][j] == 'S') return false;
//         }
//     }
//     return ret;
// }

// int main() {
//     cin >> n;
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n; j++) {
//             cin >> cor[i][j];
//             switch(cor[i][j]) {
//                 case 'T': teacher.emplace_back(i, j); break;
//                 case 'S': student.emplace_back(i, j); break;
//                 case 'X': space.emplace_back(i, j); break;
//             }
//         }
//     }
//     vector<bool> perm(space.size());
//     fill(perm.end()-3, perm.end(), true);
//     int tmp = 0;
//     do {
//         for(int i = 0; i < perm.size() && tmp < 4; i++) {
//             if(perm[i]) {
//                 cor[space[i].first][space[i].second] = 'O';
//                 tmp++;
//             }
//         }
//         if(isAvoidWatch()) { ans = true; break; }
//         tmp = 0;
//         for(int i = 0; i < perm.size() && tmp < 4; i++) {
//             if(perm[i]) {
//                 cor[space[i].first][space[i].second] = 'X';
//                 tmp++;
//             }
//         }
//         tmp = 0;
//     } while(next_permutation(perm.begin(), perm.end()));
//     if(ans) cout << "YES\n";
//     else cout << "NO\n";
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<char>> hallway(6, vector<char>(6, 'X'));
vector<pair<int, int>> teachers;
vector<pair<int, int>> candidate;
int d[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
bool isInHallway(int i, int j) { return i > -1 && i < n && j > -1 && j < n; }

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> hallway[i][j];
            if(hallway[i][j] == 'T') teachers.emplace_back(i, j);
        }
    }

    for(int i = 0; i < (int)teachers.size(); i++) {
        int ti = teachers[i].first, tj = teachers[i].second;
        for(int k = 0; k < 4; k++) {
            int ni = ti+d[k][0], nj = tj+d[k][1];
            while(isInHallway(ni, nj)) {
                if(hallway[ni][nj] == 'S') {
                    ni += d[3-k][0]; nj += d[3-k][1];
                    int cnt = 0;
                    while(!(ni == ti && nj == tj)) {
                        candidate.emplace_back(ni, nj); 
                        ni += d[3-k][0]; nj += d[3-k][1];
                        cnt++;
                    }
                    if(cnt == 0) { // 이미 실패
                        cout << "NO\n";
                        return 0;
                    }
                    break;
                }
                ni += d[k][0]; nj += d[k][1];
            }
        }
    }

    sort(candidate.begin(), candidate.end());
    unique(candidate.begin(), candidate.end());
    bool isYes = true;

    for(int x = 0; x < (int)candidate.size()-2; x++) {
        hallway[candidate[x].first][candidate[x].second] = 'O';
        for(int y = x+1; y < (int)candidate.size()-1; y++) {
            hallway[candidate[y].first][candidate[y].second] = 'O';
            for(int z = y+1; z < (int)candidate.size(); z++) {
                hallway[candidate[z].first][candidate[z].second] = 'O';
                
                isYes = true;
                for(int i = 0; (i < (int)teachers.size()) && isYes; i++) {
                    int ti = teachers[i].first, tj = teachers[i].second;
                    for(int k = 0; (k < 4) && isYes; k++) {
                        int ni = ti+d[k][0], nj = tj+d[k][1];
                        while(isInHallway(ni, nj)) {
                            if(hallway[ni][nj] == 'S') { // 이미 이 경우는 통과못함
                                isYes = false;
                                break;
                            }
                            if(hallway[ni][nj] == 'O') break;
                            ni += d[k][0]; nj += d[k][1];
                        }
                    }
                }

                if(isYes) break; // 여러 장애물 경우 중 하나라도 통과면 통과
                hallway[candidate[z].first][candidate[z].second] = 'X';
            }
            if(isYes) break; // 여러 장애물 경우 중 하나라도 통과면 통과
            hallway[candidate[y].first][candidate[y].second] = 'X';
        }
        if(isYes) break; // 여러 장애물 경우 중 하나라도 통과면 통과
        hallway[candidate[x].first][candidate[x].second] = 'X';
    }

    if(isYes) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}