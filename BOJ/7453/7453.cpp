#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> vs;
vector<vector<int>> pvs;

void makePairVector(vector<int> a, vector<int> b) {
    vector<int> ret;
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            ret.push_back(a[i]+b[j]);
        }
    }
    pvs.push_back(ret);
}

int main() {
    int ans = 0;
    cin >> n;
    for(int i = 0; i < 4; i++) {
        vector<int> tmpv;
        vs.push_back(tmpv);
    }
    int tmp;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> tmp;
            vs[j].push_back(tmp);
        }
    }
    makePairVector(vs[0], vs[1]);
    makePairVector(vs[2], vs[3]);
    sort(pvs[0].begin(), pvs[0].end());
    sort(pvs[1].begin(), pvs[1].end());
    int i = 0, j = pvs[1].size()-1;
    while(i < pvs[0].size()) {
        int com = pvs[0][i] + pvs[1][j];
        if(com == 0) {
            ans++;
            i++;
            j--;
        } else if(com > 0) {
            i++;
        } else {
            j--;
        }
    }
    cout << ans << endl;
    return 0;
}