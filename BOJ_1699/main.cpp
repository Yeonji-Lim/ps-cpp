#include <cstdio>
#define MAX 100001
int dp[MAX];

int min(int a, int b) { return a < b? a: b; }

int squareNumSum(int n) {
    if(dp[n] != MAX) return dp[n];
    int & ret = dp[n];
    for(int i = 1; i <= n; i++) {
        if(i*i > n) {
            break;
        } else if(i*i == n) {
            ret = 1;
            break;
        } else if(i*i < n) {
            ret = min(ret, squareNumSum(i*i) + squareNumSum(n - i*i));
        }
    }
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i <= n; i++) {
        dp[i] = MAX;
    }
    dp[0] = 0;
    printf("%d\n", squareNumSum(n));
    return 0;
}
