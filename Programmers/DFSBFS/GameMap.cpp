// 1844
#include<vector>
#include<queue>
#define MS 101
using namespace std;
int n, m;

int isInMap(int i, int j) { return i > -1 && i < n && j > -1 && j < m; }

int solution(vector<vector<int>> maps) {
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dist[MS][MS];
    int ci, cj, ni, nj;
    queue<pair<int, int>> q;
    
    n = maps.size(); m = maps[0].size();
    fill(&dist[0][0], &dist[n][m], -1);
    dist[0][0] = 1;
    q.push({0, 0});
    
    while(!q.empty()) {
        ci = q.front().first; cj = q.front().second;
        q.pop();
        if(ci == n-1 && cj == m-1) break;
        for(int k = 0; k < 4; k++) {
            ni = ci + d[k][0]; nj = cj + d[k][1];
            if(isInMap(ni, nj) && dist[ni][nj] == -1 && maps[ni][nj] == 1) {
                dist[ni][nj] = dist[ci][cj]+1;
                q.push({ni, nj});
            }
        }
    }
    
    return dist[n-1][m-1];
}