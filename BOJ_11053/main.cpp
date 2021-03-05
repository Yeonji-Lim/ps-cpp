/* 2021.3.5 Failed */
//#include <cstdio>
//#include <vector>
//#include <utility>
//using namespace std;
//#define MAX 1000
//
//int main() {
//    int n, i, j, tmp;
//    pair<int, int> tmp_p;
//    vector<pair<int, int>> v;
//    scanf("%d", &n);
//    for(i = 0; i < n; i++) {
//        scanf("%d", &tmp);
//        if(v.empty()) {
//            tmp_p = make_pair(tmp, 1);
//            v.push_back(tmp_p);
//        } else {
//            j = 0;
//            bool flag = false;
//            while(j < v.size()) {
//                if(v[j].first <= tmp) {
//                    v[j].first = tmp;
//                    v[j].second++;
//                    if(!flag) flag = !flag;
//                }
//                j++;
//            }
//            if(!flag) {
//                tmp_p = make_pair(tmp, 1);
//            }
//        }
//    }
//    tmp = v[0].second;
//    for(j = 0; j < v.size(); j++) {
//        if(v[j].second > tmp) tmp = v[j].second;
//    }
//    printf("%d\n", tmp);
//    return 0;
//}

#include <cstdio>
#define MAX 1000

int max(int a, int b) { return a > b? a: b; }

int main() {
    int dp[MAX] = {};
    int nums[MAX] = {};
    int n, i, j, tmp;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &tmp);
        nums[i] = tmp;
    }
    tmp = 0;
    for(i = 0; i < n; i++) {
        dp[i] = 1;
        for(j = 0; j < i; j++) {
            if(nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        tmp = max(tmp, dp[i]);
    }
    printf("%d\n", tmp);
    return 0;
}