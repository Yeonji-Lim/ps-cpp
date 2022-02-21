#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int N, M, K, X;
vector<int> dist;
vector<vector<int>> graph;
deque<int> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K >> X;
    dist.resize(N, 1000000);
    graph.resize(N);

    int i, j, distNum = 0;
    for(int x = 0; x < M; x++) {
        cin >> i >> j;
        graph[i].push_back(j);
    }

    dq.push_back(X);
    while(!dq.empty()) {
        i = dq.front();
        dq.pop_back();
        distNum++;
        for(j = 0; j < graph[i].size(); j++) {
            int t = graph[i][j];
            if (distNum < dist[t]) {
                
            }
        }
    }

    return 0;
}