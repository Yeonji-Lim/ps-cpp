#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, rst = 0;
vector<vector<int>> box;
vector<vector<int>> tmpV;
int dij[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
bool isInBox(int i, int j) { return i >= 0 && i < N && j >= 0 && j < N; }
int max(int x, int y) { return x > y? x: y; }

void findMaxCandy(vector<vector<int>> &v, int i, int j) {
    int ret = 1, cnt = 1;
    if(i == -1) {
        char pre = v[0][j];
        for(int x = 1; x < N; x++) {
            if(pre == v[x][j]) {
                cnt++;
            } else {
                pre = v[x][j];
                cnt = 1;
            }
            ret = max(ret, cnt);
        }
        v[N][j] = ret;
    } else {
        char pre = v[i][0];
        for(int x = 1; x < N; x++) {
            if(pre == v[i][x]) {
                cnt++;
            } else {
                pre = v[i][x];
                cnt = 1;
            }
            ret = max(ret, cnt);
        }
        v[i][N] = ret;
    }
}

int switchCandy(int i, int j, int ni, int nj) {
    char tmp = tmpV[i][j];
    tmpV[i][j] = tmpV[ni][nj];
    tmpV[ni][nj] = tmp;
    if(i == ni) {
        findMaxCandy(tmpV, i, -1);
        findMaxCandy(tmpV, -1, j);
        findMaxCandy(tmpV, -1, nj);
        return max(tmpV[i][N], max(tmpV[N][j], tmpV[N][nj]));
    } else {
        findMaxCandy(tmpV, -1, j);
        findMaxCandy(tmpV, i, -1);
        findMaxCandy(tmpV, ni, -1);
        return max(tmpV[N][j], max(tmpV[i][N], tmpV[ni][N]));
    }
}

int findCandy(int i, int j) {
    int ret = 0, ni, nj;

    for(int d = 0; d < 4; d++) {
        ni = i + dij[d][0]; nj = j + dij[d][1];
        if(isInBox(ni, nj) && box[ni][nj] != box[i][j]) {
            copy(box.begin(), box.end(), tmpV.begin());
            ret = max(ret, switchCandy(i, j, ni, nj));
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    box.resize(N+1, vector<int> (N+1, 0));
    tmpV.resize(N+1, vector<int> (N+1, 0));

    char c;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> c;
            box[i][j] = (int)c;
        }
    }

    for(int i = 0; i < N; i++) {
        findMaxCandy(box, i, -1);
        findMaxCandy(box, -1, i);
        rst = max(rst, max(box[i][N], box[N][i]));
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            rst = max(rst, findCandy(i, j));
            if(rst == N) break;
        }
        if(rst == N) break;
    }

    cout << rst << endl;
    return 0;
}