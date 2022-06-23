#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    char val;
    int i;
    int j;
    bool visited = false;
    Node* parent = NULL;
    int g = 0;
    int h = 0;
    Node(char _val, int _i, int _j) : val(_val), i(_i), j(_j){};
};
int n, m, r, k;
int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
bool isInMap(int i, int j) { return -1 < i && i < n && -1 < j && j < m; }
int h(int i, int j, pair<int, int> t) { return max(t.first, i) - min(t.first, i) + max(t.second, j) - min(t.second, j); }
priority_queue<Node> open;

void aStar(int si, int sj, vector<vector<Node *>> map, int mode) {
    map[si][sj]->visited = true;

}

int main() {
    int T;
    string str;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> n >> m >> r >> k;
        vector<vector<Node*>> map(n, vector<Node*>(m));
        for(int i = 0; i < n; i++) {
            cin >> str;
            for(int j = 0; j < m; j++) {
                map[i][j] = new Node(str[j], i, j);
            }
        }
        aStar(0, 0, map, 0);
        cout << endl;
    }
    return 0;
}
