#include <iostream>
#include <limits.h>
using namespace std;

int V, E, start_node;
int graph[100][100];
int parent[100];
bool visited[100] = {false};

int min(int a, int b) { return a < b? a: b; }

int findSmallestPathNode() {
    int idx = -1, tmp = INT_MAX;
    for(int i = 1; i <= V; i++) {
        if(!visited[i] && tmp > parent[i]) {
            tmp = parent[i];
            idx = i;
        }
    }
    return idx;
}

void updateTable(int cur_idx) {
    int cur_score = parent[cur_idx];
    for(int j = 1; j <= V; j++){
        if(graph[cur_idx][j] != -1)
            parent[j] = min(parent[j], cur_score + graph[cur_idx][j]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> V >> E;
    cin >> start_node;

    fill(&graph[0][0], &graph[V+1][V+1], -1);
    fill_n(parent, V+1, INT_MAX);
    parent[start_node] = 0;

    int i, j;
    for(int e = 0; e < E; e++) {
        cin >> i >> j >> graph[i][j];
        graph[j][i] = graph[i][j];
    }

    i = findSmallestPathNode();
    while (i != -1) {
        visited[i] = true;
        updateTable(i);
        i = findSmallestPathNode();
    }

    for (i = 1; i <= V; cout << parent[i] << endl, i++);

    return 0;
}
