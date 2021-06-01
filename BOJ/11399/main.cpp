/* 2021.6.1 Solved - 1228KB 0ms */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, tmp, rst = 0;
    vector<int> v;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    tmp = 0;
    for(int i = 0; i < n; i++) {
        tmp += v[i];
        rst += tmp;
    }
    printf("%d", rst);
    return 0;
}
