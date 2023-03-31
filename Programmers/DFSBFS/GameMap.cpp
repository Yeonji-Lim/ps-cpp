// 1844
#include<vector>
#include<string>
#define MS 101
using namespace std;
vector<vector<int>> map;
int n, m;
int dist[MS][MS];

int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int isInMap(int i, int j) { return i > -1 && i < n && j > -1 && j < m; }

void find(int i, int j) {
    if(i == n-1 && j == m-1) return;
    int ni, nj;
    for(int k = 0; k < 4; k++) {
        ni = i + d[k][0]; nj = j + d[k][1];
        if(isInMap(ni, nj) && dist[ni][nj] == -1 && map[ni][nj] == 1) {
            dist[ni][nj] = dist[i][j]+1;
            find(ni, nj);
        }
    }
}

int solution(vector<vector<int>> maps) {
    map = maps;
    n = maps.size();
    m = maps[0].size();
    fill(&dist[0][0], &dist[n][m], -1);
    dist[0][0] = 1;
    find(0, 0);
    return dist[n-1][m-1];
}