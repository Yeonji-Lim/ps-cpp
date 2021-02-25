#include <cstdio>
#include <cstring>
#define MOD 10007
int cache[1001][10];

void ascentNumber(int n) {
    if(cache[n][0] != -1) return;
    if(cache[n-1][0] == -1) {
        ascentNumber(n-1);
    }
    for(int i = 0; i < 10; i++) {
        if(i == 0) {
            cache[n][i] = cache[n-1][i];
        } else {
            cache[n][i] = cache[n][i-1] + cache[n-1][i];
        }
    }
    return;
}

int main() {
    int n, i, rst;
    for(i = 1; i < 1001; i++) {
        if(i == 1) memset(cache[1], 1, sizeof(cache[1]));
        else memset(cache[i], -1, sizeof(cache[i]));
    }
    scanf("%d", &n);
    printf("%d %d\n", cache[1][1], cache[2][1]);
    ascentNumber(n);
    for(i = 0; i <10; i++) {
        rst = (rst + cache[n][i]) % MOD;
    }
    printf("%d", rst);
    return 0;
}
