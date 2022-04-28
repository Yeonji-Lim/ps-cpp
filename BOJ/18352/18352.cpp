#include <bits/stdc++.h>
using namespace std;
vector<int> graph[300001];
vector<int> dist(300001, -1);
int n, m, k, x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> k >> x;
    int i, j;
    for(int p = 0; p < m; p++) {
        cin >> i >> j;
        graph[i].push_back(j);
    }
    dist[x] = 0;

    queue<int> q;
    q.push(x);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(i = 0; i < graph[cur].size(); i++) {
            j = graph[cur][i];
            if (dist[j] == -1) {
                dist[j] = dist[cur]+1;
                q.push(j);
            }
        }
    }
    
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