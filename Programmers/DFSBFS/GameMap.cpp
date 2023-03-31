#include<vector>
#define MS 101
#define MA 10002
using namespace std;
vector<vector<int>> map;
int n, m;
int dist[MS][MS];

int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int isInMap(int i, int j) { return i > -1 && i < n && j > -1 && j < m; }

int find(int i, int j) {
    if(i == n-1 && j == m-1) {
        return dist[i][j];
    }
    int ni, nj, ans = MA;
    for(int k = 0; k < 4; k++) {
        ni = i + d[k][0]; nj = j + d[k][1];
        if(isInMap(ni, nj) && dist[ni][nj] == 0 && map[ni][nj] == 1) {
            dist[ni][nj] = dist[i][j]+1;
            ans = min(ans, find(ni, nj));
        }
    }
    if(ans == MA) return -1;
    return ans;
}

int solution(vector<vector<int>> maps) {
    map = maps;
    n = maps.size();
    m = maps[0].size();
    return find(0, 0);
}