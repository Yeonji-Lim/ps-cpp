#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool isBGWithBfs(int start, vector<int> graph[], bool visited[], int color[]) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        int parent = q.front();
        q.pop();
        for(int i = 1; i < graph[parent].size(); i++) {
            int child = graph[parent][i];
            if(color[child] * color[graph[parent][i-1]] == -1) {
                return false;
            }
            if(!visited[child]) {
                visited[child] = true;
                q.push(child);
            }
        }
    }
    return true;
}

int main() {
    int k, v, e;
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d %d", &v, &e);
        vector<int> graph[v+1];
        bool visited[v+1];
        int color[v+1];
        fill(visited, visited+v+1, false);
        fill(color, color+v+1, 0);
        for(int j = 0; j < e; j++) {
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
            color[a] = 1;
            color[b] = -1;
        }
        for(int j = 1; j <= v; j++) {
            sort(graph[j].begin(), graph[j].end());
        }
        for(int j = 1; j <= v; j++) {
            if(!visited[j]) {
                if(!isBGWithBfs(j, graph, visited, color)) {
                    printf("NO\n"); break;
                }
            }
            if(j == v) { printf("YES\n"); break; }
        }

    }
    return 0;
}
