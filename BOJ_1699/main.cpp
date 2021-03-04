#include <cstdio>
#define MAX 100001
int dp[MAX];

int min(int a, int b) { return a > b? b: a; }

int squareNumSum(int n) {
    int & ret = dp[n];
    if(ret != MAX) return ret;
    for(int i = n; i > 0; i--) {
        if((i*i) == n) {
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
