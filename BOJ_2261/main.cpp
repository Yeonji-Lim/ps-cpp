/* 2021.5.19 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int d = 40000;

int min(int a, int b) { return a<b? a: b; }

bool compare (pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}

int distance (pair<int, int> a, pair<int, int> b) {
    return (int)sqrt(pow(a.first-b.first, 2) + pow(a.second-b.second,2));
}

int main() {
    int n, x, y;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        v.emplace_back(x, y);
    }
    sort(v.begin(), v.end(), compare);
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(v[i].first == v[j].first) {
                if(v[j].second-v[i].second >= d) break;
                else d = distance(v[i], v[j]);
            } else {
                if(v[j].first-v[i].first >= d || v[j].second-v[i].second >= d) break;
                else {
                    d = min(d, distance(v[i], v[j]));
                }
            }
        }
    }
    printf("%d\n", (int)pow(d, 2));
    return 0;
}
