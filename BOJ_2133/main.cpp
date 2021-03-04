#include <cstdio>
#include <cstring>
#define MAX 31
int dp[MAX];

int tiling(int n) {
    int & ret = dp[n];
    if(ret != 0) return ret;
    ret = 3*tiling(n-1) + 2*tiling(n-2);
    return ret;
}

int main() {
    int n;
    memset(dp, 0, sizeof(dp));
    scanf("%d", &n);
    if(n%2 == 1) {
        printf("0\n");
    } else {
        dp[0] = 1;
        dp[1] = 3;
        printf("%d\n", tiling(n/2));
    }
    return 0;
}
