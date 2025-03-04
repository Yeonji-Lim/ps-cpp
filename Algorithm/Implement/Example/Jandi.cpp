#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long cut(vector<int> &v, int k, int d) {
    long long ret = 0;
    for(int i = 0; i < k; i++) {
        pop_heap(v.begin(), v.end());
        ret += v.back()-1+d;
        v.pop_back();
        v.push_back(1-d);
        push_heap(v.begin(), v.end());
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T, n, m, D, k, tmp;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        vector<int> v;
        long long ans = 0;
        cin >> n >> m >> D;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> tmp;
                v.push_back(tmp);
            }
        }
        make_heap(v.begin(), v.end());

        for(int d = 1; d <= D; d++) {
            cin >> k;
            ans += d * cut(v, k, d);
        }
        cout << "#" << t << " " << ans << endl;
    }
}
