/* 2021.4.20 */
#include <cstdio>
#include <vector>
#define MAX 100001
using namespace std;
vector<pair<int, int>> tree[MAX];
bool visited[MAX];
int rst = 0;
int farthestNode = 0;

int max(int a, int b) { return a > b? a: b; }

void dfs(int start, int ret) {
    if(visited[start]) return;
    int origin = ret;
    visited[start] = true;
    for(int i = 0; i < tree[start].size(); i++) {
        pair<int, int> next = tree[start][i];
        dfs(next.first, origin + next.second);
    }
}

int main() {
    int v, a, b, c;
    scanf("%d", &v);
    vector<pair<int, int>> tree[v+1];
    bool visited[v+1];
    for(int i = 1; i <= v; i++) {
        scanf("%d", &c);
        visited[c] = false;
        while(true) {
            scanf("%d", &a);
            if(a == -1) break;
            scanf("%d", &b);
            tree[c].push_back(make_pair(a, b));
        }
    }
    c = dfs(1, tree, visited, 0);
    printf("%d\n", &c);
    return 0;
}