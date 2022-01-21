#include <iostream>
#include <limits.h>
#include <queue>
using namespace std;

int n, m, c;
int graph[30000][30000];
bool visited[30000] = {false};
int table[30000];
priority_queue<pair<int, int>> pq;

void updateTable(int cur) {
    int new_score;
    for(int i = 1; i <= n; i++) {
        new_score = table[cur] + graph[cur][i];
        if (new_score > 0 && table[i] > new_score){
            table[i] = new_score;
            pq.emplace(table[i], i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> c;
    fill(&graph[0][0], &graph[n+1][n+1], INT_MAX);
    fill(&table[0], &table[n+1], INT_MAX);

    int i, j, k;
    for(int x = 0; x < m; x++) {
        cin >> i >> j >> k;
        graph[i][j] = k;
    }

    table[c] = 0;
    pq.emplace(table[c], c);
    while(!pq.empty()) {
        i = pq.top().second;
        pq.pop();
        if(visited[i]) continue;
        visited[i] = true;
        updateTable(i);
    }
    
    j = n-1;
    k = 0;
    for(i = 1; i <= n; i++) {
        if(table[i] == INT_MAX) j--;
        else if(table[i] > k) k = table[i];
    }

    cout << j << " " << k << endl;

    return 0;
}