/* 2021.5.11 Failed - 시간 초과 */
//#include <cstdio>
//#include <vector>
//#include <algorithm>
//using namespace std;
//vector<int> v, priV;
//int cnt = 0;
//
//void countSwap() {
//    if(v.empty()) return;
//    for(int i = 0; i < v.size(); i++) {
//        if(v[i] == priV.back()) {
//            cnt += v.size()-i-1;
//            v.erase(v.begin()+i);
//            priV.pop_back();
//            countSwap();
//        }
//    }
//}
//
//int main() {
//    int n, tmp;
//    scanf("%d", &n);
//    for(int i = 0; i < n; i++) {
//        scanf("%d", &tmp);
//        v.push_back(tmp);
//    }
//    priV.assign(v.begin(), v.end());
//    sort(priV.begin(), priV.end());
//    countSwap();
//    printf("%d", cnt);
//    return 0;
//}

/* 2021.5.14 시간 초과 */
//#include <cstdio>
//#include <vector>
//#include <algorithm>
//using namespace std;
//vector<int> v;
//vector<int> tmpV;
//int main() {
//    int n, tmp, rst = 0;
//    scanf("%d", &n);
//    for(int i = 0; i < n; i++) {
//        scanf("%d", &tmp);
//        v.push_back(tmp);
//    }
//    tmpV = v;
//    sort(tmpV.begin(), tmpV.end());
//    while(!tmpV.empty()) {
//        for(int i = 0; i < v.size(); i++) {
//            if(v[i] == tmpV.back()) {
//                rst += v.size()-1-i;
//                v.erase(v.begin()+i);
//                tmpV.pop_back();
//                break;
//            }
//        }
//    }
//    printf("%d\n", rst);
//    return 0;
//}

/* 2021.5.14 */
#include <cstdio>
#include <vector>
using namespace std;
int ret = 0;

void countSwap(vector<int> lv, vector<int> rv) {
    for(int i = 0; i < lv.size(); i++)
        for (int j = 0; j < rv.size(); j++)
            if (lv[i] > rv[j]) ret++;
}

void mergeSort (vector<int> v) {
    if(v.size() == 1) return;
    vector<int> lv, rv;
    int mid = v.size()/2;
    lv.assign(v.begin(), v.begin()+mid);
    rv.assign(v.begin()+mid+1, v.end());

    mergeSort(lv);
    mergeSort(rv);

    countSwap(lv, rv);
}

int main() {
    int n, tmp;
    vector<int> v;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
    mergeSort(v);
    printf("%d", ret);
    return 0;
}