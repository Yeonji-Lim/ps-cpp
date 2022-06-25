#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1600000000
using namespace std;
vector<int> cost(16);
vector<vector<int>> pairs;

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

    // 미리 n = 1일 때 나올 수 있는 모든 조합을 저장한다. 
    // 이는 테스트 케이스에 대해 독립적이다.
    for(int i = 0; i < 8; i++) {
        pairs.push_back({0, i, 15-i}); // 2개씩 짝

        vector<bool> cur = toMbti(i);
        for(int j = 0; j < 4; j++) { // 4개씩 짝
            vector<int> item = {0, i};
            vector<bool> mbti = cur;
            mbti[j] = !mbti[j];
            for(int k = 0; k < 4; k++) {
                if(k == j) continue;
                mbti[k] = !mbti[k];
                item.push_back(toIdx(mbti));
                mbti[k] = !mbti[k];
            }
            pairs.push_back(item);
        }
    }

    for(int i = 0; i < 16; i++) { // 3개씩 짝
        vector<bool> cur = toMbti(i);
        vector<bool> sel(4);
        fill(sel.end()-2, sel.end(), true);
        do {
            vector<int> item = {0, i};
            vector<bool> mbti = cur;
            for(int j = 0; j < 4; j++) {
                if(sel[j]) mbti[j] = !mbti[j];
            }
            for(int j = 0; j < 4; j++) {
                if(sel[j]) continue;
                mbti[j] = !mbti[j];
                item.push_back(toIdx(mbti));
                mbti[j] = !mbti[j];
            }
            pairs.push_back(item);
        } while(next_permutation(sel.begin(), sel.end()));
    }

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++) {
        int n, ans, tmp = 0;
        cin >> n;
        for(int i = 0; i < 16; i++) {
            cin >> cost[i];
        }

        for(int i = 0; i < (int)pairs.size(); i++) {
            for(int j = 1; j < (int) pairs[i].size(); j++) {
                tmp += cost[pairs[i][j]];
            }
            pairs[i][0] = tmp;
            tmp = 0;
        }
        sort(pairs.begin(), pairs.end());

        ans = pairs[0][0];
        if(n != 1) {
            vector<vector<int>> prevs;
            prevs.push_back(pairs[0]);
            tmp = 1;
            for (int i = 1; i < n; i++) {
                while(tmp < (int)pairs.size() && isOverlap(prevs, pairs[tmp])) tmp++;
                if(tmp == pairs.size()) break;
                prevs.push_back(pairs[tmp]);
                ans += pairs[tmp][0];
                tmp++;
            }
        }
        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}
