#include <cstdio>
#include <vector>
using namespace std;
vector<pair<long long int, int>> v;

bool findNum (long long int tmp) {
    for(int i = 0; i < v.size(); i++) {
        if(v[i].first == tmp) {
            v[i].second++;
            return true;
        }
    }
    return false;
}

int main() {
    int n, i;
    long long int tmp;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%lld", &tmp);
        if(!findNum(tmp)) {
            v.push_back(make_pair(tmp, 1));
        }
    }
    n = 1;
    for(i = 0; i < v.size(); i++) {
        if(v[i].second > n) {
            n = v[i].second;
            tmp = v[i].first;
        } else if(v[i].second == n && v[i].first < tmp) {
            tmp = v[i].first;
        }
    }
    printf("%d\n", tmp);
    return 0;
}
