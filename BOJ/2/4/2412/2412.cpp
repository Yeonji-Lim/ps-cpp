#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n, T, ci, cj, dist;
vector<vector<int>> grooves;
queue<vector<int>> q;
bool canGo(int ci, int cj, int ni, int nj) { return abs(ci-ni) <= 2 && abs(cj-nj) <= 2; }

int findMinIdx(int ti) {
    int l = 0, r = grooves.size()-1, m;
    while(l < r) {
        m = (l + r)/2;
        if(grooves[m][0] < ti-2) {
            l = m+1;
        } else if(grooves[m][0] > ti-2) {
            r = m;
        } else {
            return m;
        }
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> T;
    
    for(int i = 0; i < n; i++) {
        cin >> ci >> cj;
        grooves.emplace_back(vector<int>{ci, cj, 0, 0});
    }
    sort(grooves.begin(), grooves.end());

    q.emplace(vector<int>{0, 0, 1, 0});
    while(!q.empty()) {
        ci = q.front()[0]; cj = q.front()[1]; dist = q.front()[3];
        q.pop();
        if(cj == T) {
            cout << dist << '\n';
            return 0;
        }
        for(int i = findMinIdx(ci); i < n; i++) {
            if(canGo(ci, cj, grooves[i][0], grooves[i][1]) && !grooves[i][2]) {
                grooves[i][2] = 1;
                grooves[i][3] = dist + 1;
                q.emplace(grooves[i]);
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}