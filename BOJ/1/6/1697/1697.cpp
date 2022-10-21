#include <bits/stdc++.h>
using namespace std;
int n, k;
int dist[100001];

int findSec(int cur) {
    if(cur < 0) return 100002;
    if(dist[cur] == -1) {
        if(cur < k) dist[cur] = min(findSec(cur+1), min(findSec(cur-1), findSec(cur*2))) + 1;
        else dist[cur] = cur-k;  
    }
    return dist[cur];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    fill_n(dist, 100001, -1);
    cout << findSec(n) << '\n';
}