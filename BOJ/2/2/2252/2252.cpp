#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph(32001, vector<int>(0, 0));
vector<int> indegree(32001, 0);
queue<int> targets;
int n, m, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            targets.push(i);
            indegree[i] = -1;
        }
    }
    while(!targets.empty()) {
        int target = targets.front();
        cout << target << " ";
        targets.pop();
        for(int i = 0; i < graph[target].size(); i++) {
            indegree[graph[target][i]]--;
        }
        for(int i = 1; i <= n; i++) {
            if(indegree[i] == 0) {
                targets.push(i);
                indegree[i] = -1;
            }
        }
    }
    cout << '\n';
    return 0;
}