#include <iostream>
#include <vector>
using namespace std;

int N, M, x, y, K;
int dice[6] = {0, };
int cur=0, nor=1, wes=2;
vector<vector<int>> map;

bool isInMap(int i, int j) { return i > -1 && i < N && j > -1 && j < M; }

void copy() {
    if(map[x][y] == 0) {
        map[x][y] = dice[cur];
    } else {
        dice[cur] = map[x][y];
        map[x][y] = 0;
    }
}

bool rotateDice(int direc) {
    int prevCur = cur;
    switch(direc) {
        case 1:
            if(!isInMap(x, y+1)) break;
            cur = 5-wes;
            wes = prevCur;
            y++; copy();
            return true;
        case 2:
            if(!isInMap(x, y-1)) break;
            cur = wes;
            wes = 5-prevCur;
            y--; copy();
            return true;
        case 3:
            if(!isInMap(x-1, y)) break;
            cur = nor;
            nor = 5-prevCur;
            x--; copy();
            return true;
        case 4:
            if(!isInMap(x+1, y)) break;
            cur = 5-nor;
            nor = prevCur;
            x++; copy();
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> x >> y >> K;
    
    map.resize(N, vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    int cmd;
    for(int i = 0; i < K; i++) {
        cin >> cmd;
        if(rotateDice(cmd)) cout << dice[5-cur] << endl;
    }
}