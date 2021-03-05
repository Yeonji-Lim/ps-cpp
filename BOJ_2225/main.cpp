/* 2021.3.5 Solved - 1272KB 12ms */
#include <cstdio>
#define MAX 201
#define MOD 1000000000
int dp[MAX][MAX] = {0};

int disassemble(int n, int k) {
    int & ret = dp[n][k];
    if(ret != 0 || k == 0) return ret;
    for(int i = 0; i <= n; i++) {
        ret = (ret + disassemble(i, k-1)) % MOD;
    }
    return ret;
}

int main() {
    int n, k, i;
    scanf("%d %d", &n, &k);
    for(i = 0; i < MAX; i++) {
        dp[i][1] = 1;
    }
    printf("%d", disassemble(n, k));
    return 0;
}
