#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, M, real_rst = 0, virus_rst = 0;
vector<vector<int>> graph;
deque<pair<int, int>> dq;

int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};

int min(int a, int b) { return a < b? a : b; }
int max(int a, int b) { return a > b? a : b; }
bool isInGraph(int x, int j) { return i >= 0 && i < N && j >= 0 && j < M; }

void pushDQ(int x, int y) {
    int nx, ny;
    for(int i = 0; i < 2; i++) {
        nx = x + di[i]; ny = y + dj[i];
        if(isInGraph(nx, ny)) {
            visited[i][j];
            
        }
    }
}

int virusSpread(vector<vector<int>> &v) {
    int ret = 0;
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(v[i][j] == 2 && !visited[i][j]) {
                visited[i][j] = true;
                while(!dq.empty()) {

                }
            }
        }
    }

    return ret;
}

int main() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    graph.resize(N, vector<int>(M, 0));

    for(int i = 0; i < N; i++ ){
        for(int j = 0; j < M; j++){
            cin >> graph[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            
        }
    }

    return 0;
}