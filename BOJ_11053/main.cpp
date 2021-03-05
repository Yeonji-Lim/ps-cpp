#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
#define MAX 1000

int main() {
    int n, i, j, tmp;
    pair<int, int> tmp_p;
    vector<pair<int, int>> v;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if(v.empty()) {
            tmp_p = make_pair(tmp, 1);
            v.push_back(tmp_p);
        } else {
            j = 0;
            bool flag = false;
            while(j < v.size()) {
                if(v[j].first <= tmp) {
                    v[j].first = tmp;
                    v[j].second++;
                    if(!flag) flag = !flag;
                }
                j++;
            }
            if(!flag) {
                tmp_p = make_pair(tmp, 1);
            }
        }
    }
    tmp = v[0].second;
    for(j = 0; j < v.size(); j++) {
        if(v[j].second > tmp) tmp = v[j].second;
    }
    printf("%d\n", tmp);
    return 0;
}
