/* 2021.4.19 Solved - 79516KB 148ms */
#include <cstdio>
#include <deque>
#define MAX 100001
using namespace std;
deque<int> tree[MAX];
int rst[MAX];

void findParent (int current, int parent) {
    if(current != 1) {
        rst[current] = parent;
        for(int i = 0; i < tree[current].size(); i++) {
            if(tree[current][i] == parent) tree[current].erase(tree[current].begin()+i);
        }
    }
    while(!tree[current].empty()) {
        findParent(tree[current].front(), current);
        tree[current].pop_front();
    }
}

int main() {
    int n, a, b;
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    findParent(1, 0);
    for(int i = 2; i <= n; i++) {
        printf("%d\n", rst[i]);
    }
    return 0;
}