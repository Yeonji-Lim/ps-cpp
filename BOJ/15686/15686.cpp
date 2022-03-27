#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

int N, M, ans=0, si=0, sj=0, hnum=0;
vvi map, cMap, chicRank;

bool compare(vi a, vi b) { return a[0] > b[0]; }
int subAbs(int a, int b) { return a > b? a-b: b-a; }

int chicDist(int hi, int hj) {
    int dist = 100; // N의 범위안에서 절대 나올 수 없는 큰값
    int ci, cj, tmp;
    for(int i = 0; i < N; i++) { for(int j = 0; j < N; j++) {
        if(map[i][j] == 2) {
            tmp = subAbs(i, hi)+subAbs(j, hj);
            if(dist > tmp){
                dist = tmp;
                ci = i; cj = j;
            }
        }
    }}
    cMap[ci][cj]++;
    return dist;
}

void helpFunc() {
    int mi = si/hnum, mj = sj/hnum, ci, cj;
    vvi tmp;
    for(int i = 0; i < N; i++) {
        for(int j =0; j <N; j++) {
            if(map[i][j] == 2) {
                tmp.push_back(vi{subAbs(mi, i)+subAbs(mj, j), i, j});
            }
        }
    }
    sort(tmp.begin(), tmp.end());
    for(int i = 0; i < tmp.size(); i++) {
        ci = tmp[i][1]; cj = tmp[i][2];
        cMap[ci][cj] += M-i;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    map.resize(N, (vi(N, 0)));
    cMap.resize(N, (vi(N, 0)));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(map[i][j] == 1) {
                cMap[i][j] = chicDist(i, j);
                si+=i; sj+=j;
                hnum++;
            }
        }
    }
    helpFunc();

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(map[i][j] == 2) chicRank.push_back(vi{cMap[i][j], i, j});
        }
    }
    sort(chicRank.begin(), chicRank.end(), compare);
    for(int i = M; i < chicRank.size(); i++) {
        map[chicRank[i][1]][chicRank[i][2]] = 0;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(map[i][j] == 1) ans += chicDist(i, j);
        }
    }
    cout << ans << endl;

    return 0;
}