/* 음료수  얼려먹기 BFS */
// #include <iostream>
// #include <deque>
// using namespace std;

// int n, m, ans = 0;
// int map[1001][1001];
// int di[4] = {-1, 1, 0, 0};
// int dj[4] = {0, 0, -1, 1};
// deque<pair<int, int>> dq;
// bool isInMap(int i, int j) { return (i > -1 && i < n && j > -1 && j < m); }

// void bfs(){
//     int i = dq.front().first, j = dq.front().second;
//     dq.pop_front();
//     for(int k = 0; k < 4; k++) {
//         int ni = i + di[k], nj = j + dj[k];
//         if(isInMap(ni,nj) && map[ni][nj] == 0) {
//             map[ni][nj] = 1;
//             dq.emplace_back(ni, nj);
//         }
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);

//     cin >> n >> m;
//     string tmp;
//     for(int i = 0; i < n; i++) {
//         cin >> tmp;
//         for(int j = 0; j < m; j++) {
//             map[i][j] = tmp[j]-'0';
//         }
//     }

//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < m; j++) {
//             if(map[i][j] == 0) {
//                 dq.emplace_back(i, j);
//                 while(!dq.empty()) bfs();
//                 ans++;
//             }
//         }
//     }

//     cout << ans << '\n';
    
//     return 0;
// }

/* 20220216 */
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, M;
vector<string> box;
deque<pair<int, int>> dq;
vector<vector<bool>> visited;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    box.resize(N, "0");
    visited.resize(N, vector<bool>(M, false));
    
    for(int i = 0; i < N; i++) {
        cin >> box[i];
    }

    int i, j, rst = 0;
    dq.emplace_back(0, 0);
    for(int x = 0; x < N; x++) {
        for(int y = 0; y < M; y++) {
            if(box[x][y] == '0') {
                rst++;
                dq.emplace_back(x, y);
                while(!dq.empty()) {
                    i = dq.front().first;
                    j = dq.front().second;
                    box[i][j] = '1';
                    dq.pop_front();

                    if(i+1 < N && box[i+1][j] == '0') dq.emplace_back(i+1, j);
                    if(j+1 < M && box[i][j+1] == '0') dq.emplace_back(i, j+1);
                }
            }
        }
    }
    
    cout << rst << endl;
    
    return 0;
}