// 20230224
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
#define MS 1001
bool board[MS][MS];
bool visited[MS];
int n, m, v, i, j;
stack<int> st;

void dfs() {
    while(!st.empty()) {
        int c = st.top();
        st.pop();
        cout << c << ' ';
        for(int k = 1; k <= n; k++) {
            if(board[c][k] && !visited[k]) {
                visited[k] = true;
                st.push(k);
                dfs();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(&board[0][0], &board[MS][MS], false);
    fill_n(visited, MS, false);
    cin >> n >> m >> v;
    for(int k = 0; k < m; k++) {
        cin >> i >> j;
        board[i][j] = true;
    }

    visited[v] = true;
    st.push(v);
    dfs();

    cout << '\n';
    fill_n(visited, n, false);

    queue<int> q;
    visited[v] = true;
    q.push(v);
    while(!q.empty()) {
        int c = q.front();
        q.pop();
        cout << c << ' ';
        for(int k = 1; k <= n; k++) {
            if(board[c][k] && !visited[k]) {
                visited[k] = true;
                q.push(k);
            }
        }
    }
    
}