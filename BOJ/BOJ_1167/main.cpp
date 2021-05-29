/* 2021.4.20 Solved - 7736KB 112ms 근데 마지막에 왜 rst 0으로 초기화하는 건지 모르겟..*/
#include <cstdio>
#include <vector>
#include <cstring>
#define MAX 100001
using namespace std;
vector<pair<int, int>> tree[MAX];
bool visited[MAX];
int rst = 0;
int farthestNode = 0;

void dfs(int start, int ret) {
    if(visited[start]) return;
    visited[start] = true;
    if(rst < ret) {
        rst = ret;
        farthestNode = start;
    }
    for(int i = 0; i < tree[start].size(); i++) {
        pair<int, int> next = tree[start][i];
        dfs(next.first, ret + next.second);
    }
}

int main() {
    int v, a, b, c;
    scanf("%d", &v);
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
    dfs(1, 0);
    memset(visited, false, sizeof(visited));
    rst = 0;
    dfs(farthestNode, 0);
    printf("%d\n", rst);
    return 0;
}