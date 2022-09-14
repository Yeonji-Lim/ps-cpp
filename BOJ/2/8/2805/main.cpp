/* 2021.4.25 Solved - 5020KB 244ms */
#include <cstdio>
#define MAX 1000000
int n, rst;
long long m;
int trees[MAX];

long long cuttingRst (int h) {
    long long ret = 0;
    for(int i = 0; i < n; i++) {
        if(trees[i]-h > 0) ret += trees[i] - h;
    }
    return ret;
}

void findHeight (int l, int r) {
    int mid = (l+r)/2;
    if(l >= r || mid == l || mid == r) {
        rst = l;
        return;
    }
    if(cuttingRst(mid) > m) {
        findHeight(mid, r);
    } else if(cuttingRst(mid) < m) {
        findHeight(l, mid);
    } else {
        rst = mid;
    }
}

int main() {
    int r = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &trees[i]);
        if(trees[i] > r) r = trees[i];
    }
    findHeight(0, r);
    printf("%d\n", rst);
    return 0;
}