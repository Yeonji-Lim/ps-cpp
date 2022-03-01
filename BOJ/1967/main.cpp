#include <cstdio>
#include <vector>
#include <cstring>
#define MAX 10001
using namespace std;
vector<pair<int, int>> tree[MAX];
bool visited[MAX];
int farthestNode;
int rst = 0;

void dfs (int current, int cost) {
    if(visited[current]) return;
    visited[current] = true;
    if(rst < cost) {
        rst = cost;
        farthestNode = current;
    }
    for(int i = 0; i < tree[current].size(); i++) {
        pair<int, int> next = tree[current][i];
        dfs(next.first, cost + next.second);
    }
}

int main() {
    int n, a, b, c;
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        tree[a].push_back(make_pair(b, c));
    }
    dfs(1, 0);
    memset(visited, false, sizeof(visited));
    rst = 0;
    dfs(farthestNode, 0);
    printf("%d\n", rst);
    return 0;
}
