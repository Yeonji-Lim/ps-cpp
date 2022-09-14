#include <bits/stdc++.h>
using namespace std;
const int MAX = 8;

int N, M, ans;
int lab[MAX][MAX];
int tmp[MAX][MAX];
int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
bool isInMap(int i, int j) { return -1 < i && i < N && -1 < j && j < M; }

void bfs() {
    int after[MAX][MAX];

    for(int i = 0; i < N; i++) 
        for(int j = 0; j < M; j++)
            after[i][j]  = tmp[i][j];

    queue<pair<int, int>>q;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(after[i][j] == 2)
                q.emplace(i, j);

    while(!q.empty()) {
        int x = q.front().first; int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x+d[i][0], ny = y+d[i][1];
            if(isInMap(nx, ny) && after[nx][ny] == 0){
                after[nx][ny] = 2;
                q.emplace(nx, ny);
            }
        }
    }

    int empty = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(after[i][j] == 0)
                empty++;
    
    ans = max(ans, empty);
}

void makeWall(int cnt) {
    if(cnt == 3) {
        bfs();
        return;
    }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(tmp[i][j] == 0) {
                tmp[i][j] = 1;
                makeWall(cnt+1);
                tmp[i][j] = 0;
            }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < M; j++)
            cin >> lab[i][j];
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(lab[i][j] == 0) {
                for(int k = 0; k < N; k++)
                    for(int l = 0; l < M; l++)
                        tmp[k][l] = lab[k][l];
                tmp[i][j] = 1;
                makeWall(1);
                tmp[i][j] = 0;
            }

    cout << ans << endl;
    return 0;
}