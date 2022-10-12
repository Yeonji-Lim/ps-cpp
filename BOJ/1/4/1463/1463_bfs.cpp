#include <bits/stdc++.h>
using namespace std;
int dist[3000000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    fill_n(dist, 3000000, -1);
    dist[1] = 0;
    for(int i = 1; i < n; i++) {
        if(dist[i+1] == -1) dist[i+1] = dist[i] + 1;
        else dist[i+1] = min(dist[i+1], dist[i] + 1);
        if(dist[i*2] == -1) dist[i*2] = dist[i] + 1;
        else dist[i*2] = min(dist[i*2], dist[i] + 1);
        if(dist[i*3] == -1) dist[i*3] = dist[i] + 1;
        else dist[i*3] = min(dist[i*3], dist[i] + 1);
    }
    cout << dist[n] << '\n';
}