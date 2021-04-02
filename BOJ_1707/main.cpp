/* 2021.4.2 1차 시도 - Failed */
//#include <cstdio>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//bool isBGWithBfs(int start, vector<int> graph[], bool visited[], int color[]) {
//    queue<int> q;
//    q.push(start);
//    visited[start] = true;
//    while(!q.empty()) {
//        int parent = q.front();
//        q.pop();
//        for(int i = 1; i < graph[parent].size(); i++) {
//            int child = graph[parent][i];
//            if(color[child] * color[graph[parent][i-1]] == -1) {
//                return false;
//            }
//            if(!visited[child]) {
//                visited[child] = true;
//                q.push(child);
//            }
//        }
//    }
//    return true;
//}
//
//int main() {
//    int k, v, e;
//    scanf("%d", &k);
//    for(int i = 0; i < k; i++) {
//        scanf("%d %d", &v, &e);
//        vector<int> graph[v+1];
//        bool visited[v+1];
//        int color[v+1];
//        fill(visited, visited+v+1, false);
//        fill(color, color+v+1, 0);
//        for(int j = 0; j < e; j++) {
//            int a, b;
//            scanf("%d %d", &a, &b);
//            graph[a].push_back(b);
//            graph[b].push_back(a);
//        }
//        for(int j = 1; j <= v; j++) {
//            sort(graph[j].begin(), graph[j].end());
//            if(color[j] == 0) {
//                if(j%2 == 0) color[j] = 1;
//                else color[j] = -1;
//            }
//            for(int k = 0; k < graph[j].size(); k++) {
//                color[k] = color[j]*(-1);
//            }
//        }
//        for(int j = 1; j <= v; j++) {
//            if(!visited[j]) {
//                if(!isBGWithBfs(j, graph, visited, color)) {
//                    printf("NO\n"); break;
//                }
//            }
//            if(j == v) { printf("YES\n"); break; }
//        }
//
//    }
//    return 0;
//}

/* 2021.4.2 2차 시도 - visited에 색깔도 같이 표현, bfs시 색깔 색칠, 이분 그래프 인지 여부 환인하는 함수 분리 */
/* Solved - 5352KB 424ms */
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void bfs(int start, vector<int> graph[], int visited[]) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while(!q.empty()) {
        int parent = q.front();
        q.pop();
        int color = 2;
        if(visited[parent] == 2) color = 1;
        for(int i = 0; i < graph[parent].size(); i++) {
            int child = graph[parent][i];
            if(visited[child] == 0) {
                q.push(child);
            }
            visited[child] = color;
        }
    }
}

bool isBipartite(vector<int> graph[], int visited[], int v) {
    for(int i = 1; i <= v; i++) {
        if(graph[i].size() == 0) continue;
        for(int j = 0; j < graph[i].size(); j++) {
            if(visited[graph[i][j]] == visited[i]) return false;
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
        int visited[v+1];
        fill(visited, visited+v+1, 0);
        for(int j = 0; j < e; j++) {
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int j = 1; j <= v; j++) {
            sort(graph[j].begin(), graph[j].end());
        }
        for(int j = 1; j <= v; j++) {
            if(visited[j] == 0) {
                bfs(j, graph, visited);
            }
        }
        if(isBipartite(graph, visited, v)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}