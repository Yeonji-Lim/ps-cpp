#include <iostream>
#include <limits.h>
#include <queue>
using namespace std;

int V, E, start_node;
int graph[100][100];
int table[100];
bool visited[100] = {false};
priority_queue<pair<int, int>> pq;

int min(int a, int b) { return a < b? a: b; }

void updateTable(int cur) {
    for(int i = 1; i <= V; i++) {
        if (graph[cur][i] != -1 && table[i] > table[cur] + graph[cur][i]) {
            table[i] = table[cur] + graph[cur][i];
            pq.emplace(table[i], i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> V >> E;
    cin >> start_node;

    fill(&graph[0][0], &graph[V+1][V+1], -1);
    fill_n(table, V+1, INT_MAX);
    table[start_node] = 0;

    int i, j;
    for(int x = 0; x < E; x++) {
        cin >> i >> j >> graph[i][j];
        graph[j][i] = graph[i][j];
    }
    pq.emplace(table[start_node], start_node);

    while(!pq.empty()) {
        i = pq.top().second;
        pq.pop();
        if(visited[i]) continue;
        visited[i] = true;
        updateTable(i);
    }

    for (i = 1; i <= V; cout << table[i] << endl, i++);

    return 0;
}