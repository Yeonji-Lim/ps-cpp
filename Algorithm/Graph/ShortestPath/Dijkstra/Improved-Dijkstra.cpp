#include <iostream>
#include <limits.h>
#include <queue>
using namespace std;

int V, E, start_node;
int graph[100][100];
int parent[100];
bool visited[100] = {false};
priority_queue<pair<int, int>> pq;

int min(int a, int b) { return a < b? a: b; }

void updateTable(int cur) {
    for(int i = 1; i <= V; i++) {
        if (graph[cur][i] != -1 && parent[i] > parent[cur] + graph[cur][i]) {
            parent[i] = parent[cur] + graph[cur][i];
            pq.emplace(parent[i], i);
        }
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
    for(int x = 0; x < E; x++) {
        cin >> i >> j >> graph[i][j];
        graph[j][i] = graph[i][j];
    }
    pq.emplace(parent[start_node], start_node);

    while(!pq.empty()) {
        i = pq.top().second;
        pq.pop();
        if(visited[i]) continue;
        visited[i] = true;
        updateTable(i);
    }

    for (i = 1; i <= V; cout << parent[i] << endl, i++);

    return 0;
}