#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    int map[8][8];
    vector<pair<int, int>> candidates;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            if(map[i][j] == 0) candidates.emplace_back(i, j);
        }
    }
    vector<bool> perm(candidates.size(), false);
    fill(perm.end()-3, perm.end(), true);
    int targets[3][2];
    do {
        int j = 0;
        for(int i = 0; i < perm.size(); i++) {
            if(perm[i]){
                targets[j][0] = candidates[perm[i]].first;
                targets[j][1] = candidates[perm[i]].second;
            }
        }
    } while( next_permutation(perm.begin(), perm.end()) );

    return 0;
}