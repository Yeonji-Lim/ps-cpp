#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> graph;
vector<int> dist;
stack<int> st;
int n, m, k, x;

void dfs(int d) {
    if(st.empty()) return;
    int cur = st.top();
    for(int j = 1; j < n+1; j++) {
        if(graph[cur][j]) {
            dist[j] = min(dist[j], d+1);
            st.push(j);
            dfs(d+1);
        }
    }
    st.pop();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> k >> x;
    graph.resize(n+1, vector<bool>(n+1, false));
    dist.resize(n+1, 1000000);
    int i, j;
    for(int p = 0; p < m; p++) {
        cin >> i >> j;
        graph[i][j] = true;
    }

    st.push(x);
    dfs(0);
    
    bool find = false;
    for(i = 1; i < n+1; i++) {
        if(dist[i] != 0 && dist[i] == k) {
            cout << i << endl;
            if(!find) find = true;
        } 
    }
    if(!find) cout << -1 << endl;
    return 0;
}