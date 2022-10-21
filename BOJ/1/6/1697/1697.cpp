#include <bits/stdc++.h>
#define MAXS 20
using namespace std;
int n, k, cur, d;
int dist[MAXS];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    fill_n(dist, MAXS, -1);
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while(!q.empty()) {
        cur = q.front(); q.pop();
        d = dist[cur];
        if(cur-1 >= 0) {
            if(dist[cur-1] == -1) {
                dist[cur-1] = d+1;
                if(cur-1 != k) q.push(cur-1);
            }
        }
        if(cur+1 < MAXS && cur+1 <= k) {
            if(dist[cur+1] == -1) {
                dist[cur+1] = d+1;
                if(cur+1 != k) q.push(cur+1);
            }
        }
        if(cur*2 < MAXS) {
            if(dist[cur*2] == -1) {
                dist[cur*2] = d+1;
                if(cur*2 < k) q.push(cur*2);
                else dist[k] = min(dist[k], dist[cur*2]+cur-k);
            }
        }
    }
    cout << dist[k] << '\n';
}