/* 2021.4.27 Solved - 4312KB 324ms */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> cards;
bool findRst = false;

void findTarget (int l, int r, int x) {
    int mid = (l+r)/2;
    if(l > r) return;
    if(cards[mid] == x) findRst = true;
    else if(cards[mid] > x) {
        findTarget(l, mid-1, x);
    } else {
        findTarget(mid+1, r, x);
    }
}

int main() {
    int n, m, i, tmp;
    scanf("%d", &n);
    for(i = 0; i < n; i++ ) {
        scanf("%d", &tmp);
        cards.push_back(tmp);
    }
    sort(cards.begin(), cards.end());
    scanf("%d", &m);
    for(i = 0; i < m; i++) {
        scanf("%d", &tmp);
        findTarget(0, n, tmp);
        if(findRst) printf("1 ");
        else printf("0 ");
        findRst = false;
    }
    return 0;
}