#include <iostream>
#include <stack>
#define MS 501

using namespace std;

int board[MS][MS];
int n, m, ans = 0;

bool isInBoard(int i, int j) { return i > -1 && i < n && j > -1 && j < m; }
int d[4][2] = { {1, 0}, {0, 1}, {0, -1}, {-1, 0} };

stack<pair<int, int>> st;

void go() {
    int ci = st.top().first, cj = st.top().second, ni, nj;
    st.pop();
    
    if(ci == n-1 && cj == m-1) {
        ans++;
        return;
    }

    for(int k = 0; k < 4; k++) {
        ni = ci + d[k][0]; nj = cj + d[k][1];
        if(isInBoard(ni, nj) && board[ci][cj] > board[ni][nj]) {
            st.emplace(ni, nj);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    st.emplace(0, 0);
    while(!st.empty()) go();
    cout << ans << '\n';
    return 0;
}