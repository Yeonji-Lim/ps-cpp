#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> done(15, vector<int>(15, -1));
int n, ans = 0;

void queen(vector<vector<bool>> x, int ci, int cj, int cnt) {
    if(cnt == n) { 
        ans++; return;
    }
    done[ci][cj] = 0;
    x[ci][cj] = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == ci || j == cj || i+j == ci+cj || j-i == cj-ci) {
                x[i][j] = true;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(done[i][j] == -1 && !x[i][j]) {
                queen(x, i, j, cnt+1);
            }
        }
    }
    done[ci][cj] = 1;
    return;
}

int main() {
    cin >> n;
    vector<vector<bool>> x(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(done[i][j] == -1) queen(x, i, j, 1);
        }
    }
    cout << ans << endl;
    return 0;
}