#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long cut1(vector<int> &v, int k, int d) {
    long long ret = 0;
    for(int i = v.size()-1; i > (int)v.size()-k-1; i--) {
        ret += (long long)v[i]-1+d;
        v[i] = 1-d;
    }
    sort(v.begin(), v.end());
    return ret;
}

long long cut(priority_queue<int> &pq, int k, int d) {
    long long ret = 0;
    for(int i = 0; i < k; i++) {
        ret += pq.top()-1+d;
        pq.pop();
        pq.push(1-d);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T, n, m, D, k, tmp;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        priority_queue<int> pq;
        long long ans = 0;
        cin >> n >> m >> D;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> tmp;
                pq.push(tmp);
            }
        }
        
        for(int d = 1; d <= D; d++) {
            cin >> k;
            ans += d * cut(pq, k, d);
        }
        cout << "#" << t << " " << ans << endl;
    }
}
