/* 2021.4.10 Failed - 메모리 초과*/
//#include <cstdio>
//#include <queue>
//using namespace std;
//int graph[100000];
//bool team[100000];
//
//bool hasTeam(int num) {
//    queue<int> tmp;
//    tmp.push(num);
//    int next = graph[num];
//    while(next != tmp.front()) {
//        tmp.push(next);
//        next = graph[next];
//        if(next == tmp.back() || team[next]) return false;
//    }
//    while(!tmp.empty()) {
//        team[tmp.front()] = true;
//        tmp.pop();
//    }
//    return true;
//}
//
//int main() {
//    int t, n, rst;
//    scanf("%d", &t);
//    while(t--) {
//        rst = 0;
//        scanf("%d", &n);
//        for(int i = 1; i <= n; i++) {
//            scanf("%d", &graph[i]);
//            team[i] = false;
//        }
//        for(int i = 1; i <= n; i++) {
//            if(team[i]) continue;
//            if(!hasTeam(i)) ++rst;
//        }
//        printf("%d\n", rst);
//    }
//    return 0;
//}

/* 2021.4.12 */
#include <cstdio>
int cnt;

void dfs(int start, int graph[], bool visited[], bool done[]) {
    visited[start] = true;
    int next = graph[start];
    if(!visited[next]) {
        dfs(next, graph, visited, done);
    } else if(!done[next]) {
        for (int i = next; i != start; i = graph[i]) cnt++;
        cnt++;
    }
    done[start] = true;
}

int main() {
    int t, n;
    scanf("%d", &t);
    while(t--) {
        cnt = 0;
        scanf("%d", &n);
        int graph[n+1];
        bool visited[n+1], done[n+1];
        for(int i = 1; i <= n; i++) {
            scanf("%d", &graph[i]);
            visited[i] = false;
            done[i] = false;
        }
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) dfs(i, graph, visited, done);
        }
        printf("%d\n", n - cnt);
    }
    return 0;
}