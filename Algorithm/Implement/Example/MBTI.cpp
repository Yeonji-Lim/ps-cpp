#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1600000000
using namespace std;
vector<int> cost(16);
vector<vector<int>> pairs;
vector<bool> mbti(4);

vector<bool> toMbti(int idx) {
    vector<bool> ret;
    int com = 16;
    for(int i = 0; i < 4; i++) {
        ret.push_back(!(idx%com < com/2));
        com /= 2;
    }
    return ret;
}

int toIdx(vector<bool> mbti) {
    int ret = 0, com = 8;
    for(int i = 0; i < 4; i++) {
        if(mbti[i]) ret += com;
        com /= 2;
    }
    return ret;
}

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
    for(int t = 0; t < 16; t++) {
        vector<bool> test = toMbti(t);
        for(int i = 0; i < (int)test.size(); i++) {
            if(test[i]) cout << "1 ";
            else cout << "0 ";
        }
        cout << endl;
        cout << toIdx(test) << endl;
    }
    
    // cin >> T;
    // for(int t = 1; t <= T; t++) {
    //     int n, ans, tmp = 0;
    //     cin >> n;
    //     for(int i = 0; i < 16; i++) {
    //         cin >> cost[i];
    //     }



    //     for(int i = 0; i < 72; i++) {
    //         for(int j = 1; j < (int) pairs[i].size(); j++) {
    //             tmp += cost[pairs[i][j]];
    //         }
    //         pairs[i][0] = tmp;
    //         tmp = 0;
    //     }
    //     sort(pairs.begin(), pairs.end());
    //     ans = pairs[0][0];
    //     if(n != 1) {
    //         vector<vector<int>> prevs;
    //         prevs.push_back(pairs[0]);
    //         tmp = 1;
    //         for (int i = 1; i < n; i++) {
    //             while(tmp < (int)pairs.size() && isOverlap(prevs, pairs[tmp])) tmp++;
    //             if(tmp == pairs.size()) break;
    //             prevs.push_back(pairs[tmp]);
    //             ans += pairs[tmp][0];
    //             tmp++;
    //         }
    //     }
    //     cout << "#" << t << " " << ans << endl;
    // }
}
