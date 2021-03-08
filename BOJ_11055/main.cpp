#include <cstdio>
#define MAX 1000

int max(int a, int b) { return a > b? a: b; }

int main() {
    int n, tmp, i, j;
    scanf("%d", &n);
    int dp[MAX] = {0};
    int num[MAX] = {0};
    for(i = 0; i < n; i++) {
        scanf("%d", &tmp);
        num[i] = tmp;
        dp[i] = tmp;
    }
    tmp = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j < i; j++) {
            if(num[i] > num[j]) {
                dp[i] = max(dp[i], num[i] + dp[j]);
            }
        }
        tmp = max(tmp, dp[i]);
    }
    printf("%d\n", tmp);
    return 0;
}
