/* 2021.3.9 Solved - 1116KB 0ms */
#include <cstdio>
#define MAX 1000
int max(int a, int b) { return a > b? a: b;}

int main() {
    int n, tmp, i, j;
    int num[MAX] = {};
    int dp[MAX] = {};
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &tmp);
        num[i] = tmp;
    }
    tmp = 0;
    for(i = 0; i < n; i++) {
        dp[i] = 1;
        for(j = 0; j < i; j++) {
            if(num[i] < num[j]) {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        tmp = max(tmp, dp[i]);
    }
    printf("%d\n", tmp);
    return 0;
}
