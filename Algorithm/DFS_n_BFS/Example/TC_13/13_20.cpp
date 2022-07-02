#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> drone = {0, 0, 0, 1};
int hd[8][4] = {
    {0, -1, 0, -1}, {0, 1, 0, 1}, {-1, 0, -1, 0}, {1, 0, 1, 0}, 
    {-1, 0, 0, -1}, {-1, 1, 0, 0}, {0, 0, 1, -1}, {0, 1, 1, 0} // 대각선 이동
};
int vd[8][4] = {
    {-1, 0, -1, 0}, {1, 0, 1, 0}, {0, -1, 0, -1}, {0, 1, 0, 1}, 
    {0, -1, -1, 0}, {1, -1, 0, 0}, {0, 0, -1, 1}, {1, 0, 0, 1} // 대각선 이동
};

bool isValidPosition(vector<vector<int>> board, int i, int j) { return i > -1 && i < n && j > -1 && j < n && board[i][j] == 0; }
bool isValidMove(vector<vector<int>> board, int d[8][4], int k) {
    if(k < 4) return isValidPosition(board, d[k][0], d[k][1]) && isValidPosition(board, d[k][2], d[k][3]);
    if(k < 6) return isValidMove(board, d, 2);
    return isValidMove(board, d, 3);
}

bool isHori() { return drone[0]-drone[2] == 0; }
int hOf(int i1, int j1, int i2, int j2) { return (n-1-i1 + n-1-j1 + n-1-i2 + n-1-j2)/2; }
bool isGoal(vector<int> pos) { return (pos[0] == n-1 && pos[1] == n-1) || (pos[1] == n-1 && pos[2] == n-1); }
void newDronePosition(vector<int> node) {
    for(int i = 0; i < 4; i++) drone[i] = node[i+2];
}

struct compare {
    bool operator()(vector<int> a, vector<int> b) { return a[0]+a[1] > b[0]+b[1]; }
};

vector<vector<int>> visited;
bool isSamePosition(vector<int> a, vector<int> b) {
    for(int i = 0; i < 4; i++) if(a[i] != b[i]) return false;
    return true;
}
bool isVisited(vector<int> pos) {
    for(int i = 0; i < (int)visited.size(); i++) 
        if(isSamePosition(visited[i], pos)) return true;
    return false;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    n = (int)board.size();
    priority_queue<vector<int>, vector<vector<int>>, compare> pq;
    pq.push({0, hOf(0, 0, 0, 1), 0, 0, 0, 1, 0, 0, 0, 1});
    visited.push_back({0, 0, 0, 1});
    vector<int> node;
    while(!pq.empty()) {
        node = pq.top();
        pq.pop();
        newDronePosition(node);
        if(isHori()){
            for(int k = 0; k < 8; k++) {
                if(isValidMove(board, hd, k)){
                    vector<int> newPosition = {drone[0]+hd[k][0], drone[1]+hd[k][1], drone[2]+hd[k][2], drone[3]+hd[k][3]};
                    if(isVisited(newPosition)) continue;
                    if(isGoal(newPosition)) return node[0]+1;
                    visited.push_back(newPosition);
                    pq.push({node[0]+1, hOf(newPosition[0], newPosition[1], newPosition[2], newPosition[3]),
                                newPosition[0], newPosition[1], newPosition[2], newPosition[3],
                                drone[0], drone[1], drone[2], drone[3]});
                }
            }
        } else {
            for(int k = 0; k < 8; k++) {
                if(isValidMove(board, vd, k)){
                    vector<int> newPosition = {drone[0]+vd[k][0], drone[1]+vd[k][1], drone[2]+vd[k][2], drone[3]+vd[k][3]};
                    if(isVisited(newPosition)) continue;
                    if(isGoal(newPosition)) return node[0]+1;
                    visited.push_back(newPosition);
                    pq.push({node[0]+1, hOf(newPosition[0], newPosition[1], newPosition[2], newPosition[3]),
                                newPosition[0], newPosition[1], newPosition[2], newPosition[3],
                                drone[0], drone[1], drone[2], drone[3]});
                }
            }
        }
    }
    return answer;
}

int main() {
    int n; 
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    cout << solution(board) << endl;
    return 0;
}