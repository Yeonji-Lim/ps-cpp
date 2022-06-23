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
int n, m, r, k;

vector<vector<char>> map(100, vector<char>(100, '.'));
vector<vector<bool>> visited(100, vector<bool>(100, false));
vector<pair<int, int>> excalibur;
pair<int, int> S;

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

    Node* curNode = new Node(si, sj, NULL, 0, h(si, sj, target));
    do {
        visited[curNode->i][curNode->j] = true;
        for (int k = 0; k < 4; k++) {
            ni = curNode->i + d[k][0];
            nj = curNode->j + d[k][1];
            if (isInMap(ni, nj) && !visited[ni][nj]) { // visited가 닫힌 목록
                // 목표물에 도착하면 이동거리 반환
                if(ni == target.first && nj == target.second) {
                    // 반환 전에 초기화
                    open.clear();
                    fill(visited.begin(), visited.begin() + n, vector<bool>(m, false));
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
        if(open.empty()) return 10000;
        sort(open.begin(), open.end(), compare);
        curNode = open[0];
        open.erase(open.begin());
    } while (!open.empty());
    return 10000;
}

int main() {
    int T;
    string str;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int ans = 0;

        cin >> n >> m >> r >> k;
        for(int i = 0; i < n; i++) {
            cin >> str;
            for(int j = 0; j < m; j++) {
                map[i][j] = str[j];
                if(str[j] == 'A' || str[j] == 'B' || str[j] == 'C') excalibur.emplace_back(i, j);
                if(str[j] == 'S') S = make_pair(i, j);
            }
        }
        // 실제 인덱스에 맞추기
        r--; k--;
        for(int mode = 0; mode < 4; mode++) {
            if(excalibur.empty()) {
                // 모두 찾았으니 궁전 가기
                ans += aStar(r, k, S, mode);
                break;
            }
            // 부품 별 거리
            vector<int> dist;
            for(int i = 0; i < (int)excalibur.size(); i++) {
                // 가까운 엑스칼리버 찾기
                dist.push_back(aStar(r, k, excalibur[i], mode));
            }
            int idx = 0;
            for(int i = 1; i < (int)dist.size(); i++) {
                if(dist[idx] > dist[i]) idx = i;
            }
            ans += dist[idx];
            r = excalibur[idx].first;
            k = excalibur[idx].second;
            map[r][k] = '.';
            excalibur.erase(excalibur.begin()+idx);
        }
        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}