/* 2021.3.20 Failed - 시간 초과 */
//#include <cstdio>
//#include <vector>
//using namespace std;
//
//vector<int> merge (vector<int> v1, vector<int> v2) {
//    vector<int> ret;
//    int i = 0; int j = 0;
//    while(i != v1.size() && j != v2.size()) {
//        if(v1[i] < v2[j]) {
//            ret.push_back(v1[i]);
//            i++;
//        } else {
//            ret.push_back(v2[j]);
//            j++;
//        }
//    }
//    while(i != v1.size()) {
//        ret.push_back(v1[i]);
//        i++;
//    }
//    while(j != v2.size()) {
//        ret.push_back(v2[j]);
//        j++;
//    }
//    return ret;
//}
//
//vector<int> customSort (vector<int> v) {
//    if(v.size() == 1 || v.empty()) { return v; }
//    vector<int> ret, l, r;
//    l.insert(l.end(), v.begin(), v.begin()+v.size()/2);
//    r.insert(r.end(), v.begin()+v.size()/2, v.end());
//    l = customSort(l);
//    r = customSort(r);
//    ret = merge(l, r);
//    return ret;
//}
//
//int main() {
//    int n, k, tmp;
//    vector<int> v;
//    scanf("%d %d", &n, &k);
//    for(int i = 0; i < n; i++) {
//        scanf("%d", &tmp);
//        v.push_back(tmp);
//    }
//    v = customSort(v);
//    printf("%d\n", v[k-1]);
//    return 0;
//}

/* 2021.3.20 Solved - 50392KB 1504ms */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k, tmp;
    vector<int> v;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    printf("%d\n", v[k-1]);
    return 0;
}