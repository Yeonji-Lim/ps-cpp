#include <cstdio>
#define MAX 1000
int max(int a, int b) { return a > b? a: b; }

int main() {
    int n, tmp, i, j;
    scanf("%d", &n);
    int num[MAX] = {};
    int dp[MAX][2] = {};
    for(i = 0; i < n; i++) {
        scanf("%d", &tmp);
        num[i] = tmp;
        dp[i][0] = 1;
        dp[i][1] = 1;
    }
    tmp = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++ ) {
            if(num[i] > num[j]) {
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
            } else if(num[i] < num[j]) {
                dp[i][1] = max(dp[i][1], max(dp[j][0], dp[j][1]) + 1);
            }
        }
        tmp = max(tmp, max(dp[i][0], dp[i][1]));
    }
    printf("%d\n", tmp);
    return 0;
}
