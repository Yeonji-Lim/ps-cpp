#include <cstdio>

bool hasTeam(int num, int graph[], bool team[], int max) {
    if(team[num]) return true;
    int next = graph[num], i = 1;
    bool tmp[max+1];
    tmp[next] = true;
    while(next != num) {
        if(i > max || next == graph[next]) { return false; }
        next = graph[next];
        i++;
    }
    for(int i = 1; i <= max; i++) {
        if(tmp[i]) { team[i] = true; }
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
            if(!hasTeam(i, graph, team, n)) ++rst;
        }
        printf("%d\n", rst);
    }
    return 0;
}
