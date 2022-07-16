#include <stdio.h>
#include <stdlib.h>

int N, M;
int map[50][50];
int visited[50][50]; // 해당 지점에서 갈 수 있는 최대 길이 
int di[4] = { 0, -1, 0, 1 };
int dj[4] = { 1, 0, -1, 0 };
bool is_cycle = false;

int dfs(int i, int j);
int main() {

    scanf("%d %d\n", &N, &M);

    char c ; 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%c", &c);
            if (c == 'H') {
                map[i][j] = -1;
            }
            else{
                map[i][j] = c - '0';
            }
            visited[i][j] = -1; // 초기화. 
        }
        scanf("%c", &c); // \n
    }
    is_cycle = false;
    int result = dfs(0, 0);

    if (is_cycle) printf("-1");
    else {
        printf("%d", result);
    }
    printf("");
}

int dfs(int i, int j) {
    if (i >= N || i < 0 || j >= M || j < 0 || map[i][j] == -1 || is_cycle) {
        return 0;
    }

    int cal = -1;
    //탐색을 한번도 하지 않은 노드. white 
    if (visited[i][j] == -1) {
        visited[i][j] = 0; // 방문중  
        for (int d = 0; d < 4; d++) {
            int r = dfs(i + di[d] * map[i][j], j + dj[d] * map[i][j]) + 1;
            if (cal < r) cal = r;
        }
        // 해당 노드로부터의 경로는 모두 탐색이 끝남.  
        visited[i][j] = cal;
        return cal;
    }
    // 탐색했던 노드에 방문. 
    else if (visited[i][j] == 0) {
        // cycle 
        is_cycle = true;
        return 0; 
    }
    else {
        return visited[i][j];
    }

}