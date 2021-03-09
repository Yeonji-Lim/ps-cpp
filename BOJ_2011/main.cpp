#include <cstdio>
#include <cstring>
#define MOD 1000000
#define MAX 5000
int dp[MAX];
char code[MAX];

bool pairPossible(int n) {
    return ((code[n-1] - '0') * 10 + code[n] - '0') < 27;
}

int numOfDecode(int n) {
    int & ret = dp[n];
    if(ret != 0) return ret;
    if(pairPossible(n)) {
        ret = (numOfDecode(n-1) + numOfDecode(n-2)) % MOD;
    } else {
        ret = numOfDecode(n-1);
    }
    return ret;
}

int main() {
    memset(dp, 0, sizeof(dp));
    scanf("%s", code);
    dp[0] = 1;
    if(pairPossible(1)) {
        dp[1] = 2;
    } else {
        dp[1] = 1;
    }
    printf("%d\n", numOfDecode(strlen(code)-1));
    return 0;
}
