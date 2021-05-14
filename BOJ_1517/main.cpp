/* 2021.5.11 Failed - 시간 초과 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v, priV;
int cnt = 0;

void countSwap() {
    if(v.empty()) return;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == priV.back()) {
            cnt += v.size()-i-1;
            v.erase(v.begin()+i);
            priV.pop_back();
            countSwap();
        }
    }
}

int main() {
    int n, tmp;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
    priV.assign(v.begin(), v.end());
    sort(priV.begin(), priV.end());
    countSwap();
    printf("%d", cnt);
    return 0;
}