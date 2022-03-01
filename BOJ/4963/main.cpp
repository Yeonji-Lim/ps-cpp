/* 2021.4.13 Solved - 1128KB 0ms */
#include <cstdio>
#include <cstring>
using namespace std;
int w, h, rst = 0, map[50][50];
bool visited[50][50];
int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int i, int j) {
    visited[i][j] = true;
    int ni, nj;
    for(int k = 0; k < 8; k++) {
        ni = i + di[k];
        nj = j + dj[k];
        if(ni > -1 && nj > -1 && ni < h && nj < w
            && !visited[ni][nj] && map[ni][nj] == 1) {
            dfs(ni, nj);
        }
    }
}

int main() {
    while(1) {
        scanf("%d %d", &w, &h);
        if(w == 0 && h == 0) break;
        for(int i = 0; i < 50; i++) {
            memset(visited[i], false, sizeof(visited[0]));
        }
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(map[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j);
                    rst++;
                }
            }
        }
        printf("%d\n", rst);
        rst = 0;
    }
    return 0;
}
