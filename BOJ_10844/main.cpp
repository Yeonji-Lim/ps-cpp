#include <cstdio>
#include <cstring>
#define MOD 1000000000
int cache[101];

int numOfStairsNumber(int n) {
    int & ret = cache[n];
    if(ret != 0) return ret;
    ret = ( 2 * numOfStairsNumber(n-1) - 1) % MOD;
    return ret;
}

int main() {
    memset(cache, 0, sizeof(cache));
    cache[1] = 9;
    cache[2] = 17;
    int N;
    scanf("%d", &N);
    printf("%d", numOfStairsNumber(N));
    return 0;
}
