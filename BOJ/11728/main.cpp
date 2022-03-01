/* 2021.5.4 Solved - 10112KB 872ms */
#include <cstdio>
#include <queue>
using namespace std;
int n, m;
queue<int> a, b, rst;

int main() {
    int i, j, tmp;
    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i++) {
        scanf("%d", &tmp);
        a.push(tmp);
    }
    for(i = 0; i < m; i++) {
        scanf("%d", &tmp);
        b.push(tmp);
    }
    while(!a.empty() && !b.empty()) {
        i = a.front();
        j = b.front();
        if(i < j) {
            rst.push(i);
            a.pop();
        } else {
            rst.push(j);
            b.pop();
        }
    }
    while(!a.empty()) {
        rst.push(a.front());
        a.pop();
    }
    while(!b.empty()) {
        rst.push(b.front());
        b.pop();
    }
    while(!rst.empty()) {
        printf("%d ", rst.front());
        rst.pop();
    }
    return 0;
}