//#include <cstdio>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main() {
//    int m, n, i, a;
//    vector<int> v;
//    scanf("%d %d", &m, &n);
//    for(i = 1; i < n/2; i++) {
//        a = (2*i+1)*2;
//        if(a >= n) { break; }
//        while(a <= n) {
//            if(a >= m && a%2 == 1) {
//                v.push_back(a);
//            }
//            a += 2*i+1;
//        }
//    }
//    sort(v.begin(), v.end());
//    v.erase(unique(v.begin(), v.end()), v.end());
//    for(i = m/2; i <= n/2; i++) {
//        a = 2*i+1;
//        if(a < v[0]) printf("%d\n", a);
//        else v.erase(v.begin());
//    }
//    return 0;
//}

/* 2021.3.31 Solved - 1972KB 24ms */
#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
    bool isPrime[1000001];
    int m, n, i, j;
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    for(i = 2; i < sqrt(1000000); i++) {
        for(j = i*2; j < 1000001; j += i) {
            isPrime[j] = false;
        }
    }
    scanf("%d %d", &m, &n);
    for(i = m; i <= n; i++) {
        if(isPrime[i]) printf("%d\n", i);
    }
    return 0;
}