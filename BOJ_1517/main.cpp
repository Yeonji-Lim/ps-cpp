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

/* 2021.5.14 Failed - 시간 초과 */
//#include <cstdio>
//#include <vector>
//using namespace std;
//int ret = 0;
//vector<int> v;
//
//void countSwap(int l, int mid, int r) {
//    for(int i = l; i <= mid; i++)
//        for (int j = mid+1; j <= r; j++)
//            if (v[i] > v[j]) ret++;
//}
//
//void mergeSort (int l, int r) {
//    if(r == l) return;
//    int mid = (l+r)/2;
//    mergeSort(l, mid);
//    mergeSort(mid+1, r);
//    countSwap(l, mid, r);
//}
//
//int main() {
//    int n, tmp;
//    scanf("%d", &n);
//    for(int i = 0; i < n; i++) {
//        scanf("%d", &tmp);
//        v.push_back(tmp);
//    }
//    mergeSort(0, n-1);
//    printf("%d", ret);
//    return 0;
//}