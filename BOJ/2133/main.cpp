/* 2021.3.4 Failed */
//#include <cstdio>
//#include <cstring>
//#define MAX 31
//int dp[MAX];
//
//int tiling(int n) {
//    int & ret = dp[n];
//    if(ret != 0) return ret;
//    ret = 3*tiling(n-1) + 2*tiling(n-2);
//    return ret;
//}
//
//int main() {
//    int n;
//    memset(dp, 0, sizeof(dp));
//    scanf("%d", &n);
//    if(n%2 == 1) {
//        printf("0\n");
//    } else {
//        dp[0] = 1;
//        dp[1] = 3;
//        printf("%d\n", tiling(n/2));
//    }
//    return 0;
//}

#include <cstdio>
#include <cstring>
#define MAX 31
int dp[MAX];

int tiling(int n) {
    int & ret = dp[n];
    if(ret != -1) return ret;
    ret = 3 * tiling(n-1);
    for(int i = n-2; i > -1; i--) {
        ret += 2 * tiling(i);
    }
    return dp[n];
}

int main() {
    int n;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    if(n%2 == 1) {
        printf("0\n");
        return 0;
    }
    dp[0] = 1;
    dp[1] = 3;
    printf("%d\n", tiling(n/2));
    return 0;
}