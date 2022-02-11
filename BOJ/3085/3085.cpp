#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, rst = 0, candy[4] = {0};
vector<vector<int>> box;
vector<vector<int>> tmpV;
int dij[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
bool isInBox(int i, int j) { return i >= 0 && i < N && j >= 0 && j < N; }
int max(int x, int y) { return x > y? x: y; }

void findMaxCandy(vector<vector<int>> &v, int i, int j) {
    if(i == -1) {
        for(int x = 0; x < N; x++) {
            switch(v[x][j]){
                case 'C': candy[0]++; break;
                case 'P': candy[1]++; break;
                case 'Z': candy[2]++; break;
                case 'Y': candy[3]++; break;
            }
        }
        sort(candy, candy+4);
        v[N][j] = candy[3];
        fill_n(candy, 4, 0);
    } else {
        for(int x = 0; x < N; x++) {
            switch(v[i][x]){
                case 'C': candy[0]++; break;
                case 'P': candy[1]++; break;
                case 'Z': candy[2]++; break;
                case 'Y': candy[3]++; break;
            }
        }
        sort(candy, candy+4);
        v[i][N] = candy[3];
        fill_n(candy, 4, 0);
    }
}

int switchCandy(int i, int j, int ni, int nj) {
    char tmp = tmpV[i][j];
    tmpV[i][j] = tmpV[ni][nj];
    tmpV[ni][nj] = tmp;
    if(i == ni) { //좌우로 변경
        findMaxCandy(tmpV, -1, j);
        findMaxCandy(tmpV, -1, nj);
        return max(max(box[N][j], tmpV[N][j]), max(box[N][nj], tmpV[N][nj]));
    } else {
        findMaxCandy(tmpV, i, -1);
        findMaxCandy(tmpV, ni, -1);
        return max(max(box[i][N], tmpV[i][N]), max(box[ni][N], tmpV[ni][N]));
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