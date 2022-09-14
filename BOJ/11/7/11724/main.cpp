/* 2021.4.2 Solved - 5588KB 188ms */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int start, vector<int> graph[], bool *(&visited)) {
    visited[start] = true;
    for(int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];
        if(!visited[next]) {
            dfs(next, graph, visited);
        }
    }
}

int main() {
    int n, m, rst = 0;
    scanf("%d %d", &n, &m);
    vector<int> graph[n+1];
    bool * visited = new bool[n+1];
    fill(visited, visited+n+1, false);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i < n+1; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    for(int i = 1; i < n+1; i++) {
        if(!visited[i]) {
            dfs(i, graph, visited);
            rst++;
        }
    }
    printf("%d\n", rst);
    return 0;
}
