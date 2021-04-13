#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, cnt;
int map[25][25];
bool visited[25][25];

void dfs(int i, int j) {
    visited[i][j] = true;
    cnt++;
    if(i > 0 && !visited[i-1][j] && map[i-1][j] == 1) dfs(i-1, j);
    if(j > 0 && !visited[i][j-1] && map[i][j-1] == 1) dfs(i, j-1);
    if(i < n-1 && !visited[i+1][j] && map[i+1][j] == 1) dfs(i+1, j);
    if(j < n-1 && !visited[i][j+1] && map[i][j+1] == 1) dfs(i, j+1);
}

int main() {
    char c;
    vector<int> v;
    scanf("%d", &n);
    scanf("%c", &c);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%c", &c);
            map[i][j] = c - '0';
            visited[i][j] = false;
        }
        scanf("%c", &c);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j] == 1 && !visited[i][j]) {
                cnt = 0;
                dfs(i, j);
                v.push_back(cnt);
            }
        }
    }
    printf("%d\n", v.size());
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        printf("%d\n", v[i]);
    }
    return 0;
}