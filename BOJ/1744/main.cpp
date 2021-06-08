/* 2021.6.4 Failed */
//#include <cstdio>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main() {
//    int n, tmp, rst = 0;
//    vector<int> v;
//    scanf("%d", &n);
//    for(int i = 0; i < n; i++) {
//        scanf("%d", &tmp);
//        v.push_back(tmp);
//    }
//    tmp = n;
//    sort(v.begin(), v.end());
//    if(n == 1) { printf("%d", v[0]); return 0; }
//    for(int i = 0; i < n; i++) {
//        if(v[i] > 1) { tmp = i; break;}
//        if(v[i] < 0 && v[i+1] <= 0) {
//            rst += v[i]*v[i+1];
//            i++;
//        } else rst += v[i];
//    }
//    if(tmp == n-1) rst += v[tmp];
//    else for(int j = n-2; j > tmp-1; j -= 2) rst += v[j]*v[j+1];
//    printf("%d\n", rst);
//    return 0;
//}

/* 2021.6.8 Solved - 1228KB 0ms */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, tmp, rst = 0;
    vector<int> v;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
    if(n == 1) { printf("%d", v[0]); return 0; }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        if(v[i] > 1) break;
        if(v[i] < 0 && v[i+1] <= 0) {
            rst += v[i]*v[i+1];
            i++;
        } else rst += v[i];
    }
    reverse(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        if(v[i] < 2) break;
        if(v[i] > 1 && v[i+1] > 1) {
            rst += v[i]*v[i+1];
            i++;
        } else rst += v[i];
    }
    printf("%d\n", rst);
    return 0;
}