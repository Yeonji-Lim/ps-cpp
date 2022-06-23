#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int i;
    int j;
    Node* parent = NULL;
    int g = 0;
    int h = 0;
    Node(int _i, int _j, Node* _parent, int _g, int _h) : i(_i), j(_j), parent(_parent), g(_g), h(_h){};
};
int n, m;

vector<vector<char>> map(100, vector<char>(100, '.'));
vector<vector<bool>> visited(100, vector<bool>(100, false));

int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
bool isInMap(int i, int j) { return -1 < i && i < n && -1 < j && j < m; }
int h(int i, int j, pair<int, int> t) { return max(t.first, i) - min(t.first, i) + max(t.second, j) - min(t.second, j); }

bool compare(Node* a, Node* b) { return a->g+a->h < b->g+b->h; }
vector<Node*> open;
int isInOpen(int i, int j) {
    for(int idx = 0; idx < (int)open.size(); idx++) {
        if(open[idx]->i == i && open[idx]->j == j) return idx;
    }
    return -1;
}

int aStar(int si, int sj, pair<int, int> target, int mode) {
    int ni, nj, tmp;
    Node* curNode;
    open.push_back(new Node(si, sj, NULL, 0, h(si, sj, target)));
    do {
        sort(open.begin(), open.end(), compare);
        curNode = open[0];
        open.erase(open.begin());
        visited[curNode->i][curNode->j] = true;
        for (int k = 0; k < 4; k++) {
            ni = curNode->i + d[k][0];
            nj = curNode->j + d[k][1];
            if (isInMap(ni, nj) && !visited[ni][nj]) { // visited가 닫힌 목록
                // 목표물에 도착하면 이동거리 반환
                if(ni == target.first && nj == target.second) {
                    return curNode->g+1;
                }
                // 목표물이 아닌 다른 것인 경우 다음꺼 확인
                if (map[ni][nj] == 'A' || map[ni][nj] == 'B' || map[ni][nj] == 'C') continue;
                // 산에 못가는 경우 다음꺼 확인
                if (mode < 3 && map[ni][nj] == 'X') continue;
                // 열린목록에 없으면 추가 있으면 갱신 여부 확인
                tmp = isInOpen(ni, nj);
                if (tmp == -1) open.push_back(new Node(ni, nj, curNode, curNode->g+1, h(ni, nj, target)));
                else if (open[tmp]->g > curNode->g+1) {
                    open[tmp]->parent = curNode;
                    open[tmp]->g = curNode->g+1;
                }
            }
        }        
    } while (!open.empty());
    return 10000;
}

int subProcess(int r, int k, vector<pair<int, int>> excalibur, pair<int, int> S) {
    int ret = 0;
    vector<char> exChar;
    for(int mode = 0; mode < 4; mode++) {
        if(mode == 3) {
            // 모두 찾았으니 궁전 가기
            ret += aStar(r, k, S, mode);
            open.clear();
            fill(visited.begin(), visited.begin() + n, vector<bool>(m, false));
            for(int i = 0; i < 3; i++) {
                map[excalibur[i].first][excalibur[i].second] = exChar[i];
            }
            break;
        }
        // 엑스칼리버 부품찾기
        ret += aStar(r, k, excalibur[mode], mode);
        r = excalibur[mode].first;
        k = excalibur[mode].second;
        exChar.push_back(map[r][k]);
        map[r][k] = '.';
        open.clear();
        fill(visited.begin(), visited.begin() + n, vector<bool>(m, false));
    }
    return ret;
}

int main() {
    int T;
    string str;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int r, k, ans = 10000;
        cin >> n >> m >> r >> k;

        vector<pair<int, int>> excalibur;
        pair<int, int> S;
        for(int i = 0; i < n; i++) {
            cin >> str;
            for(int j = 0; j < m; j++) {
                map[i][j] = str[j];
                if(str[j] == 'A' || str[j] == 'B' || str[j] == 'C') excalibur.emplace_back(i, j);
                if(str[j] == 'S') S = make_pair(i, j);
            }
        }
        r--; k--;
        sort(excalibur.begin(), excalibur.end());
        do {
            ans = min(ans, subProcess(r, k, excalibur, S));
        } while(next_permutation(excalibur.begin(), excalibur.end()));        
        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}