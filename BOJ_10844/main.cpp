#include <cstdio>
#include <cstring>
#define MOD 1000000000
int cache[101][10];

void stairsNumber(int n) {
    if(cache[n][1] != 0) {
        return;
    } else if(cache[n-1][0] == 0) {
        stairsNumber(n-1);
    }
    for(int i = 0; i < 10; i++) {
        if(i == 0) {
            cache[n][i] = cache[n-1][1];
        } else if(i == 9) {
            cache[n][i] = cache[n-1][8];
        } else {
            cache[n][i] = (cache[n-1][i+1] + cache[n-1][i-1]) % MOD;
        }
    }
    return;
}

int main() {
    memset(cache, 0, sizeof(cache));
    for(int i = 1; i < 10; i++) {
        cache[1][i] = 1;
    }
    int N, rst = 0;
    scanf("%d", &N);
    stairsNumber(N);
    for(int i = 0; i < 10; i++) {
        rst += cache[N][i];
    }
    printf("%d", rst % MOD);
    return 0;
}
