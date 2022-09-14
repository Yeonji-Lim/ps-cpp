/* 2021.5.29 Failed - 시간 초과 */
//#include <cstdio>
//#include <vector>
//#include <algorithm>
//using namespace std;
//vector<pair<int, int>> v;
//
//int max (int a, int b) { return a > b? a: b; }
//
//int numOfCon (int tgt) {
//    int ret = 1, endTime, startTime = tgt;
//    for(int i = tgt+1; i < v.size(); i++) {
//        endTime = v[tgt].first + v[tgt].second;
//        if(v[i].first > endTime) {
//            ret++;
//            tgt = i;
//        }
//    }
//    return ret;
//}
//
//int main() {
//    int n, a, b;
//    vector<vector<pair<int, int>>> r;
//    vector<pair<int, int>> t;
//    scanf("%d", &n);
//    for(int i = 0; i < n; i++) {
//        scanf("%d %d", &a, &b);
//        v.emplace_back(a, b-a);
//    }
//    sort(v.begin(), v.end());
//    a = -1;
//    for(int i = 0; i < n; i++) {
//        a = max(a, numOfCon(i));
//    }
//    printf("%d\n", a);
//    return 0;
//}

/* 2021.5.31 Solved - 2776KB 40ms */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int n, a, b, i, rst = 1;
    vector<pair<int, int>> v;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        v.emplace_back(a, b);
    }
    sort(v.begin(), v.end(), compare);
    for(i = 0; i < n; i++){
        printf(" %d %d |", v[i].first, v[i].second);
    }
    a = v[0].second;
    i = 1;
    while(true) {
        if(i == v.size()) break;
        if(v[i].first >= a) {
            a = v[i].second;
            rst++;
        }
        i++;
    }
    printf("%d", rst);
    return 0;
}