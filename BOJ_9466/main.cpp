#include <cstdio>
#include <queue>
using namespace std;

bool hasTeam(int num, int graph[], bool team[]) {
    queue<int> tmp;
    tmp.push(num);
    int next = graph[num];
    while(next != tmp.front()) {
        tmp.push(next);
        next = graph[next];
        if(next == tmp.back() || team[next]) return false;
    }
    while(!tmp.empty()) {
        team[tmp.front()] = true;
        tmp.pop();
    }
    return true;
}

int main() {
    int t, n, rst;
    scanf("%d", &t);
    while(t--) {
        rst = 0;
        scanf("%d", &n);
        int graph[n+1];
        bool team[n+1];
        for(int i = 1; i <= n; i++) {
            scanf("%d", &graph[i]);
            team[i] = false;
        }
        for(int i = 1; i <= n; i++) {
            if(team[i]) continue;
            if(!hasTeam(i, graph, team)) ++rst;
        }
        printf("%d\n", rst);
    }
    return 0;
}
