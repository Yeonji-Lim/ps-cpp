/* 미로 탈출 BFS*/
#include <iostream>
#include <climits>
#include <deque>
using namespace std;

int n, m, ans = 0;
int map[201][201];
deque<pair<int, int>> dq;
bool isInMap(int i, int j) { return (i > -1 && i < n && j > -1 && j < m); }
int min(int a, int b) { return a < b ? a : b; }

int solvingF() {
    int ret = INT_MAX;
    int i = dq.front().first, j = dq.front().second;
    dq.pop_front();
    if(i == n-1 && j == m-1) return 1;
    for(int k = 0; k < 2; k++){
        int ni = i+k, nj = j+1-k;
        if(isInMap(ni, nj) && map[ni][nj]==1){
            dq.emplace_back(ni, nj);
            ret = min(ret, solvingF()+1);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string tmp;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        for(int j = 0; j < m; j++) {
            map[i][j] = tmp[j];
        }
    }
    dq.emplace_back(0, 0);
    ans = 1+solvingF();
    cout << ans << '\n';
}