/* 2021.5.19 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

int min(int a, int b) { return a<b? a: b; }

bool compare (pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int distancePow (pair<int, int> a, pair<int, int> b) {
    return pow(a.first-b.first, 2) + pow(a.second-b.second,2);
}

int main() {
    int n, x, y, d;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        v.emplace_back(x, y);
    }
    sort(v.begin(), v.end(), compare);
    d = distancePow(v[0], v[1]);
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(i==0 && j==1) continue;
            if(v[i].first == v[j].first) {
                if(abs(v[j].second-v[i].second) >= sqrt(d)) break;
                else d = pow(v[j].second-v[i].second, 2);
            } else {
                if(v[j].first-v[i].first >= sqrt(d) || abs(v[j].second-v[i].second) >= sqrt(d)) break;
                else d = min(d, distancePow(v[i], v[j]));
            }
        }
    }
    printf("%d\n", d);
    return 0;
}
