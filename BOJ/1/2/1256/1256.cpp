#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> DP(201, vector<int>(101, 0));
int n, m, k, cnt = 1;

int combiCheck(int a, int b) {
    if(DP[a][b] != 0) return DP[a][b] > k? -1: DP[a][b];
    if(b == 0 || b == a) {
        DP[a][b] = 1;
    } else {
        DP[a][b] = combiCheck(a-1, b-1) == -1? -1: DP[a-1][b-1];
        if(DP[a][b] != -1) DP[a][b] += combiCheck(a-1, b) == -1? -DP[a][b]-1: DP[a-1][b];
    }
    return DP[a][b] > k? -1: DP[a][b];
}

int main() {
    cin >> n >> m >> k;
    if(k == 1) {
        for(int i = 0; i < n; i++) {
            cout << 'a';
        }
        for(int i = 0; i < m; i++) {
            cout << 'z';
        }
        cout << '\n';
        return 0;
    }
    DP[0][0] = 1;
    DP[1][0] = 1;
    DP[1][1] = 1;
    if(combiCheck(n+m, m) != -1) {
        cout << "-1\n";
        return 0;
    }
    k-=2;
    int q = k/m, r = k%m;
    for(int i = 0; i < n-q-1; i++) {
        cout << 'a';
    }
    for(int i = 0; i < 1+r; i++) {
        cout << 'z';
    }
    cout << 'a';
    for(int i = 0; i < m-1-r; i++) {
        cout << 'z';
    }
    for(int i = 0; i < q; i++) {
        cout << 'a';
    }
    cout << '\n';
    return 0;
}