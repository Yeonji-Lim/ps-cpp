/* 2021.4.1 Solved - 1364KB 4ms */
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

void dfs(int v, vector<int> graph[], bool visited[]) {
    stack<int> s;
    s.push(v);
    printf("%d ", v);
    visited[v] = true;
    while(!s.empty()) {
        int current = s.top();
        s.pop();
        for(int i = 0; i < graph[current].size(); i++) {
            int next = graph[current][i];
            if(!visited[next]) {
                printf("%d ", next);
                visited[next] = true;
                s.push(current);
                s.push(next);
                break;
            }
        }
    }
    return;
}

void bfs(int v, vector<int> graph[], bool visited[]) {
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while(!q.empty()) {
        int parent = q.front();
        printf("%d ", parent);
        q.pop();
        for(int i = 0; i < graph[parent].size(); i++) {
            int child = graph[parent][i];
            if(!visited[child]) {
                q.push(child);
                visited[child] = true;
            }
        }
    }
}

int main() {
    int n, m, v;
    scanf("%d %d %d", &n, &m, &v);
    vector<int> graph[n+1];
    bool visited[n+1];
    fill(visited, visited+n+1, false);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i < n+1; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(v, graph, visited);
    printf("\n");
    fill(visited, visited+n+1, false);
    bfs(v, graph, visited);
    return 0;
}