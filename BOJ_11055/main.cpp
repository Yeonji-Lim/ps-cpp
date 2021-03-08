#include <cstdio>
#define MAX 1000
int dp[MAX];
int num[MAX];

int max(int a, int b) { return a > b? a: b; }

int main() {
    int n, tmp, i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &tmp);
        num[i] = tmp;
        dp[i] = tmp;
    }
    tmp = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j < i; j++) {
            if(num[i] > num[j]) {
                dp[i] = max(dp[i], dp[i]+num[j]);
            }
        }
        tmp = max(tmp, dp[i]);
    }
    printf("%d", tmp);
    return 0;
}
