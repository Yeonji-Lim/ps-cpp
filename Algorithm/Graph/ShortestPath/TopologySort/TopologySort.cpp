#include <iostream>
#include <queue>
using namespace std;

int V, E;
bool graph[100][100];
int indegree[100] = {0};
queue<int> q;
queue<int> rst_q;

int find_zero() {
    for(int x = 1; x <= V; x++) {
        if(indegree[x] == 0) {
            indegree[x]--;
            return x;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> V >> E;

    fill(&graph[0][0], &graph[V+1][V+1], false);
    int i, j;
    for(int x = 0; x < E; x++) {
        cin >> i >> j;
        graph[i][j] = true;
        indegree[j]++;
    }

    i = find_zero();
    if (i != -1) q.push(i);

    while (!q.empty()) {
        i = q.front();
        q.pop();
        rst_q.push(i);
        for(j = 1; j <= V; j++) {
            if(graph[i][j]){
                graph[i][j] = false;
                indegree[j]--;
            }
        }
        i = find_zero();
        if(i != -1) q.push(i); //없을 때 예외처리 꼭 해주자
    }

    while(!rst_q.empty()){
        cout << rst_q.front() << " ";
        rst_q.pop();
    }
    cout << endl;

    return 0;
}