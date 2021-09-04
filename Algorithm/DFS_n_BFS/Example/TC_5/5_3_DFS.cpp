/* 음료수  얼려먹기 DFS */
#include <iostream>
#include <stack>
using namespace std;

int n, m, ans = 0;
bool isInMap(int i, int j) { return (i > -1 && i < n && j > -1 && j < m); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int map[1001][1001];
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    stack<pair<int, int>> st;
    string tmp;

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        for(int j = 0; j < m; j++) {
            map[i][j] = tmp[j]-'0';
        }
    }
    
    for(int i = 0; i < n; i++) { for(int j = 0; j < m; j++) {
        if(map[i][j]==0){
            st.emplace(i, j);
            while(!st.empty()) {
                int ci = st.top().first, cj = st.top().second;
                map[ci][cj] = 1; st.pop();
                for(int k = 0; k < 4; k++) {
                    int ni = ci+di[k], nj = cj+dj[k];
                    if(isInMap(ni, nj) && map[ni][nj]==0) st.emplace(ni, nj);
                }
            }
            ans++;
        }
    }}

    cout << ans << '\n';

    return 0;
}