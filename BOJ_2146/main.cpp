/* 2021.4.14 토마토 방법 쓰려다가 테두리를 따로 잡고 섬을 인식하는 것을 또 따로 해야해서 복잡 */
//#include <cstdio>
//#include <queue>
//using namespace std;
//int n, map[100][100];
//bool v[100][100], b[100][100];
//int di[4] = {-1, 0, 1, 0};
//int dj[4] = {0, -1, 0, 1};
//
//void boundary(int i, int j) {
//    int ni, nj;
//    for(int k = 0; k < 4; k++){
//        ni = i+di[k]; nj = j+dj[k];
//        if(ni > -1 && ni < n && nj > -1 && nj < n) {
//            if(map[ni][nj] == 0) {
//
//            } else if (map[ni][nj] == 1) {
//
//            }
//        }
//    }
//}
//
//int main() {
//    int i, j, tmp;
//    queue<pair<int, int>> q;
//    scanf("%d", &n);
//    for(i = 0; i < n; i++) {
//        for(j = 0; j < n; j++) {
//            scanf("%d", &tmp);
//            if(tmp) map[i][j] = 0;
//            else map[i][j] = 1;
//            v[i][j] = false;
//        }
//    }
//    tmp = 0;
//    for(i = 0; i < n; i++) {
//        for(j = 0; j < n; j++) {
//            if(map[i][j] == 0) {
//
//            }
//        }
//    }
//    return 0;
//}

/*2021.4.14 */
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int n, rst = 0, map[100][100];
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, -1, 0, 1};
bool visit[100][100];
vector< vector< pair<int, int> > > v;

int minBridge(vector<pair<int, int>> isl1, vector<pair<int, int>> isl2) {
    int ret = 0;
    return ret;
}

void bfs(int i, int j) {
    int ni, nj, k;
    queue<pair<int, int>> q;
    vector<pair<int, int>> tmpv;
    visit[i][j] = true;
    tmpv.push_back(make_pair(i,j));
    q.push(make_pair(i, j));
    while(!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        for(k = 0; k < 4; k++) {
            ni = i+di[k]; nj = j+dj[k];
            if(ni > -1 && ni < n && nj > -1 && nj < n
                && !visit[ni][nj] && map[ni][nj] == 1) {
                visit[ni][nj] = true;
                tmpv.push_back(make_pair(i,j));
                q.push(make_pair(ni, nj));
            }
        }
    }
    v.push_back(tmpv);
}

int main() {
    int i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            visit[i][j] = false;
        }
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++ ) {
            if(!visit[i][j] && map[i][j] == 1) {
                bfs(i, j);
            }
        }
    }
    for(i = 0; i < v.size()-1; i++) {

    }
    return 0;
}