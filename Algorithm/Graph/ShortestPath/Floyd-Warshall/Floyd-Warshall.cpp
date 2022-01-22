#include <iostream>
#include <limits.h>
using namespace std;
int V, E;
int graph[100][100];
int min(int a, int b) { return a<b? a: b; }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> V >> E;
    fill(&graph[0][0], &graph[V+1][V+1], INT_MAX);
    
    int i, j, k;
    for(k = 0; k < E; k++) {
        cin >> i >> j >> graph[i][j];
        graph[k][k] = 0;
    }

    for(k = 1; k <= V; k++) {
        for(i = 1; i <= V; i++) {
            for(j = 1; j <= V; j++) {
                if(graph[i][k] != INT_MAX && graph[k][j] != INT_MAX)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for(i = 1; i <= V; i++) {
        for(j = 1; j <= V; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}