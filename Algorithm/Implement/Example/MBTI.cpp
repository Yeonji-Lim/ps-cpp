#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1600000000
using namespace std;
vector<int> cost(16);
vector<vector<int>> pairIdx = {
    {0, 0, 15}, {0, 1, 14}, {0, 2, 13}, {0, 3, 12}, {0, 4, 11}, {0, 5, 10}, {0, 6, 9}, {0, 7, 8},
    {0, 0, 11, 13}, {0, 0, 11, 14}, {0, 0, 13, 14}, {0, 0, 7, 11}, {0, 0, 7, 13}, {0, 0, 7, 14},
    {0, 1, 10, 12}, {0, 1, 10, 15}, {0, 1, 12, 15}, {0, 1, 6, 10}, {0, 1, 6, 12}, {0, 1, 6, 15},
    {0, 2, 9, 12}, {0, 2, 9, 15}, {0, 2, 12, 15}, {0, 2, 5, 9}, {0, 2, 5, 12}, {0, 2, 5, 15},
    {0, 3, 8, 13}, {0, 3, 8, 14}, {0, 3, 13, 14}, {0, 3, 4, 8}, {0, 3, 4, 13}, {0, 3, 4, 14},
    {0, 4, 9, 10}, {0, 4, 9, 15}, {0, 4, 10, 15}, {0, 4, 3, 9}, {0, 4, 3, 10}, {0, 4, 3, 15},
    {0, 5, 8, 11}, {0, 5, 8, 14}, {0, 5, 11, 14}, {0, 5, 2, 8}, {0, 5, 2, 11}, {0, 5, 2, 14},
    {0, 6, 8, 11}, {0, 6, 8, 13}, {0, 6, 11, 13}, {0, 6, 1, 8}, {0, 6, 1, 11}, {0, 6, 1, 13},
    {0, 7, 9, 10}, {0, 7, 9, 12}, {0, 7, 10, 12}, {0, 7, 0, 9}, {0, 7, 0, 10}, {0, 7, 0, 12},
    {0, 0, 3, 5, 9}, {0, 0, 3, 6, 10}, {0, 0, 5, 6, 12}, {0, 0, 9, 10, 12},
    {0, 1, 2, 4, 8}, {0, 1, 2, 7, 11}, {0, 1, 4, 7, 13}, {0, 1, 8, 11, 13},
    {0, 2, 4, 7, 14}, {0, 2, 8, 11, 14}, {0, 3, 5, 6, 15}, {0, 3, 9, 10, 15},
    {0, 4, 8, 13, 14}, {0, 5, 9, 12, 15}, {0, 6, 10, 12, 15}, {0, 7, 11, 13, 14}
};
vector<int> pairCost(72);

bool isOverlap(vector<vector<int>> vs, vector<int> target) {
    for(int i = 0; i < (int)vs.size(); i++) {
        for(int j = 1; j < (int)vs[i].size(); j++) {
            for(int k = 1; k < (int)target.size(); k++) {
                if(target[k] == vs[i][j]) return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int n, ans, tmp = 0;
        cin >> n;
        for(int i = 0; i < 16; i++) {
            cin >> cost[i];
        }
        for(int i = 0; i < 72; i++) {
            for(int j = 1; j < (int) pairIdx[i].size(); j++) {
                tmp += cost[pairIdx[i][j]];
            }
            pairIdx[i][0] = tmp;
            tmp = 0;
        }
        sort(pairIdx.begin(), pairIdx.end());
        ans = pairIdx[0][0];
        if(n != 1) {
            vector<vector<int>> prevs;
            prevs.push_back(pairIdx[0]);
            tmp = 1;
            for (int i = 1; i < n; i++) {
                while(isOverlap(prevs, pairIdx[tmp])) tmp++;
                prevs.push_back(pairIdx[tmp]);
                ans += pairIdx[tmp][0];
                tmp++;
            }
        }
        cout << "#" << t << " " << ans << endl;
    }
}
