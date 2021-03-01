#include <cstdio>
#include <cstring>
#define ARR_SIZE 100001
int dp[ARR_SIZE][2];
int nums[ARR_SIZE];

void consecutive(int n) {
    if(dp[n-1][1] == 0) consecutive(n-1);
    if(dp[n-1][0] + nums[n] > nums[n] ) {
        dp[n][0] = dp[n-1][0] + nums[n];
    } else {
        dp[n][0] = nums[n];
    }
    dp[n][0] = 1;
    return;
}

int main() {
    int n, i, tmp;
    for(i = 0; i < ARR_SIZE; i++) {
        memset(dp[i], 0, sizeof(dp[0]));
    }
    memset(nums, 0, sizeof(nums));

    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        scanf("%d", &tmp);
        nums[i] = tmp;
    }

    dp[1][0] = nums[1];
    dp[1][1] = 1;
    consecutive(n);

    tmp = dp[1][0];
    for(i = 2; i <= n; i++) {
        if(dp[i][0] >= tmp) {
            tmp = dp[i][0];
        }
    }
    printf("%d\n", tmp);
    return 0;
}
