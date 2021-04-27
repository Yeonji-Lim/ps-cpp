#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> cards;
vector<int> targetNums;
int rst = 0;

void findTarget (int l, int r, int x) {
    int mid = (l+r)/2;
    if(l >= r || mid == l || mid == r) {
        if(cards[l] == x || cards[r] == x || cards[mid] == x) rst = 1;
        else rst = 0;
        return;
    }
    if(cards[mid] > x) {
        findTarget(l, mid, x);
    } else if (cards[mid] < x) {
        findTarget(mid, r, x);
    } else {
        rst = 1;
    }
}

int main() {
    int n, m, i, tmp;
    scanf("%d", &n);
    for(i = 0; i < n; i++ ) {
        scanf("%d", &tmp);
        cards.push_back(tmp);
    }
    scanf("%d", &m);
    for(i = 0; i < m; i++) {
        scanf("%d", &tmp);
        targetNums.push_back(tmp);
    }
    sort(cards.begin(), cards.end());
    for(i = 0; i < m; i++) {
        findTarget(0, m, targetNums[i]);
        targetNums[i] = rst;
        rst = 0;
    }
    for(i = 0; i < m; i++) {
        printf("%d ", targetNums[i]);
    }
    return 0;
}