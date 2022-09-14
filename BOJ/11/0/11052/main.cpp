/*2021.3.11 Solved - 5032KB 16ms*/
#include <cstdio>
#include <cstring>
#define MAX 1001
int dp[MAX][MAX];
int price[MAX];

int max(int a, int b) { return a > b? a: b; }

int totalPrice(int n, int i) {
    int & ret = dp[n][i];
    if(ret != -1) return ret;
    if(i == 0) {
        totalPrice(n, n);
        return ret;
    }
    for(int j = 1; j <= n/i; j++) {
        ret = max(ret, totalPrice(n-j*i, 0) + j*price[i]);
    }
    if(i != 1) ret = max(ret, totalPrice(n, i-1));
    dp[n][0] = max(dp[n][0], ret);
    return ret;
}

int main() {
    int n, tmp;
    scanf("%d", &n);
    for(int i = 0; i <= n; i++) {
        if(i == 0) {
            memset(dp[i], 0, sizeof(dp[0]));
        } else {
            memset(dp[i], -1, sizeof(dp[0]));
            scanf("%d", &tmp);
            price[i] = tmp;
        }
    }
    printf("%d", totalPrice(n,0));
    return 0;
}
