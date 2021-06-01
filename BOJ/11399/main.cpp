/* 2021.6.1 Solved - 1228KB 0ms */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, tmp, rst;
    vector<int> v;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    tmp = v[0];
    rst = tmp;
    for(int i = 1; i < n; i++) {
        tmp += v[i];
        rst += tmp;
    }
    printf("%d", rst);
    return 0;
}
