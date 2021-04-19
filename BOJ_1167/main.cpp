/* 2021.4.19 */
#include <cstdio>
#include <vector>
using namespace std;

int max(int a, int b) { return a > b? a: b; }

int dfs(int start, vector<pair<int, int>> tree[], bool visited[], int ret) {
    int origin = ret;
    visited[start] = true;
    for(int i = 0; i < tree[start].size(); i++) {
        pair<int, int> next = tree[start][i];
        if(!visited[next.first])
            ret = max(ret, dfs(next.first, tree, visited, origin)+next.second);
    }
    return ret;
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
