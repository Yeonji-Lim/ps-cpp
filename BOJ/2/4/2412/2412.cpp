#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n, T, cidx, ci, cj, dist;
vector<vector<int>> grooves;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> T;
    
    grooves.emplace_back(vector<int>{0, 0, 0, 0});
    for(int i = 0; i < n; i++) {
        cin >> ci >> cj;
        grooves.emplace_back(vector<int>{ci, cj, 0, 0});
    }
    sort(grooves.begin(), grooves.end());

    q.push(0);
    grooves[0][2] = 1;
    while(!q.empty()) {
        cidx = q.front();
        q.pop();
        ci = grooves[cidx][0]; cj = grooves[cidx][1]; dist = grooves[cidx][3];
        if(cj == T) {
            cout << dist << '\n';
            return 0;
        }
        for(int i = cidx-1; i > 0; i--) {
            if(ci - grooves[i][0] > 2) break;
            if(abs(cj - grooves[i][1]) <= 2 && !grooves[i][2]) {
                grooves[i][2] = 1;
                grooves[i][3] = dist + 1;
                q.push(i);
            }
        }
        for(int i = cidx+1; i < n+1; i++) {
            if(grooves[i][0] - ci > 2) break;
            if(abs(cj - grooves[i][1]) <= 2 && !grooves[i][2]) {
                grooves[i][2] = 1;
                grooves[i][3] = dist + 1;
                q.push(i);
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}