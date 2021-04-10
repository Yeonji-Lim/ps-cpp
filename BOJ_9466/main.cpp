#include <cstdio>
#include <queue>
using namespace std;

bool hasTeam(int num, int graph[], bool team[], int max) {
    if(team[num]) return true;
    queue<int> tmp;
    tmp.push(num);
    int next = graph[num], i = 1;
    while(next != tmp.front()) {
        tmp.push(next);
        next = graph[next];
        i++;
        if(i > max || next == tmp.back()) return false;
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
            if(!hasTeam(i, graph, team, n)) ++rst;
        }
        printf("%d\n", rst);
    }
    return 0;
}
