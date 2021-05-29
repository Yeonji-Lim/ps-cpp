/* 2021.5.29 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v;

int max (int a, int b) { return a > b? a: b; }

int numOfCon (int tgt) {
    int ret = 1, endTime, startTime = tgt;
    for(int i = tgt+1; i < v.size(); i++) {
        endTime = v[tgt].first + v[tgt].second;
        if(v[i].first > endTime) {
            ret++;
            tgt = i;
        }
    }
    return ret;
}

int main() {
    int n, a, b;
    vector<vector<pair<int, int>>> r;
    vector<pair<int, int>> t;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        v.emplace_back(a, b-a);
    }
    sort(v.begin(), v.end());
    a = -1;
    for(int i = 0; i < n; i++) {
        a = max(a, numOfCon(i));
    }
    printf("%d\n", a);
    return 0;
}
