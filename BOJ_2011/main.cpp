#include <cstdio>
#include <cstring>
#define MOD 1000000
#define MAX 5001
int dp[MAX];
char code[MAX];

bool pairPossible(int n) {
    int tmp = (code[n-1] - '0') * 10 + code[n] - '0';
    return tmp < 27 && 0 < tmp;
}

int numOfDecode(int n) {
    int & ret = dp[n];
    if(ret != -1) return ret;
    ret = 0;
    if(code[n-1] != '0') {
        ret = numOfDecode(n-1);
    }
    if(pairPossible(n-1)) {
        ret = (ret + numOfDecode(n-2)) % MOD;
    }
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%s", code);

    dp[0] = 1;

    if(code[0] != '0') { dp[1] = 1; }
    else { dp[1] = 0; }

    printf("%d\n", numOfDecode(strlen(code)));

    return 0;
}
