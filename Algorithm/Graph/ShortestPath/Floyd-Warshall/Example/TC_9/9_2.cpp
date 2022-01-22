#include <iostream>
#include <limits.h>
using namespace std;
int N, M, X, K;
int graph[100][100];

int min(int a, int b) { return a < b? a: b; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    fill(&graph[0][0], &graph[N+1][N+1], INT_MAX);

    int i, j, k;
    for(k = 0; k < M; k++) {
        cin >> i >> j;
        graph[i][j] = 1;
        graph[j][i] = 1;
    }
    cin >> X >> K;

    for(k = 1; k <= N; k++) {
        for(i = 1; i <= N; i++) {
            for(j = 1; j <= N; j++) {
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    if (graph[1][K] + graph[K][X] > 0)
        cout << graph[1][K] + graph[K][X] << endl;
    else
        cout << "-1" << endl;

    return 0;
}