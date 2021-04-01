#include <cstdio>
#include <cstring>

int main() {
    int n, m, v, i, a, b;
    scanf("%d %d %d", &n, &m, &v);
    bool graph[n+1][n+1];
    bool visited[n+1];
    memset(visited, false, sizeof(visited));
    for(i = 0; i < n+1; i++) { memset(graph[i], false, sizeof(graph[0])); }
    for(i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        graph[a][b] = true;
        graph[b][a] = true;
    }
    m = v; b = 0;
    while(1){
        printf("%d ", v);
        visited[v] = true;
        b++;
        for(i = 1; i < n+1; i++) {
            if(graph[v][i] && !visited[i]) {
                v = i;
                break;
            }
        }
        if(i == n+1) break;
    }
    printf("\n"); v = m;
    memset(visited, false, sizeof(visited));
    printf("%d ", v);
    visited[v] = true;
    b--;
    while(1){
        a = 0;
        for(i = 1; i < n+1; i++) {
            if(graph[v][i] && !visited[i]) {
                printf("%d ", i);
                visited[i] = true;
                b--;
                if(a == 0) a = i;
            }
        }
        v = a;
        if(b == 0) break;
    }

    return 0;
}
