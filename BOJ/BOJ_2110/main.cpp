/* 2021.4.26 Solved - 2008KB 28ms */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, c, rst = 0;
vector<int> houses;

bool isPossible (int distance) {
    int count = 1, stan = 0;
    for(int i = 1; i < n; i++) {
        if(houses[i]-houses[stan] >= distance) {
            ++count;
            stan = i;
        }
    }
    return count >= c;
}

void findRst (int l, int r) {
    int mid = (l+r)/2;
    if(l >= r || mid == l || mid == r) return;
    if(!isPossible(mid)) findRst(l, mid);
    else {
        if(rst < mid) rst = mid;
        findRst(mid, r);
    }
}

int main() {
    int x, max = 0;
    scanf("%d %d", &n, &c);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        houses.push_back(x);
        if(max < houses[i]) max = houses[i];
    }
    sort(houses.begin(), houses.begin()+n);
    findRst(0, max);
    printf("%d\n", rst);
    return 0;
}