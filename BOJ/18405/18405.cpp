#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> lab(200, vector<int>(200, 0));
deque<vector<int>> dq;
int n, k, s, x, y;

int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
bool isInMap(int i, int j) { return -1 < i && i < n && -1 < j && j < n; }

bool compare(vector<int> a, vector<int> b) { return a[0] < b[0]; }

int main() {
    int i, j;
    vector<int> tmp(3);
    cin >> n >> k;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            cin >> lab[i][j];
            if(lab[i][j] != 0) {
                tmp[0] = lab[i][j];
                tmp[1] = i;
                tmp[2] = j;
                dq.push_back(tmp);
            } 
        }
    }
    sort(dq.begin(), dq.end(), compare);
    cin >> s >> x >> y;

    int minVir = dq.front()[0];
    int vir, cnt = 0, ni, nj;
    while(!dq.empty()) {
        vir = dq.front()[0]; i = dq.front()[1]; j = dq.front()[2];
        dq.pop_front();

        if(vir == minVir) cnt++; // 지금이 cnt초번째라는 거임 
        if(cnt == s+1) break;
        for(int k = 0; k < 4; k++) {
            ni = i + d[k][0]; nj = j + d[k][1];
            if(isInMap(ni, nj) && lab[ni][nj] == 0) {
                lab[ni][nj] = vir;
                tmp[0] = vir;
                tmp[1] = ni;
                tmp[2] = nj;
                dq.push_back(tmp);
            }
        }
    }
    cout << lab[x-1][y-1] << endl;
    return 0;
}