#include <bits/stdc++.h>
#define MAXS 100002
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
    while(dist[k] == -1) {
        cur = q.front(); q.pop();
        if(cur == k) continue;
        d = dist[cur];
        for(int i : {cur-1, cur+1, cur*2}) {
            if(i != cur && i >= 0 && i <= 100002 && dist[i] == -1) {
                dist[i] = d+1;
                q.push(i);
            }
        }
    }
    cout << dist[k] << '\n';
}