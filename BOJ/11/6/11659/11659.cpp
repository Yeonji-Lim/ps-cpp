#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
vector<int> nums(100002, 0);
vector<int> DP(100002, 0);

int calDP(int i) {
    if(i < 1) return 0;
    if(DP[i] != 0) return DP[i];
    return DP[i] = calDP(i-1)+nums[i];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    calDP(n);
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << DP[b] - DP[a-1] << '\n';
    }
    return 0;
}