/* 2021.4.14 Solved - 1228KB 0ms */
#include <cstdio>
#include <queue>
using namespace std;

int main() {
    int n, m, i, j, k, ni, nj, map[100][100];
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, -1, 0, 1};
    char c;
    queue<pair<int, int>> q;
    scanf("%d %d", &n, &m);
    scanf("%c", &c);
    for(i = 0; i < n; i++) {
        for(j = 0; j <m; j++) {
            scanf("%c", &c);
            map[i][j] = c-'0';
        }
        scanf("%c", &c);
    }
    q.push(make_pair(0,0));
    while(!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        for(k = 0; k < 4; k++) {
            ni = i+di[k]; nj = j+dj[k];
            if(ni > -1 && ni < n && nj > -1 && nj < m && map[ni][nj] == 1) {
                q.push(make_pair(ni, nj));
                map[ni][nj] = map[i][j] + 1;
            }
        }
    }
    printf("%d\n", map[n-1][m-1]);
    return 0;
}