#include <cstdio>
#include <cstring>
int cache[11];

int numOfSol(int n) {
    int & ret = cache[n];
    if(ret != 0) return ret;
    ret = numOfSol(n-1) + numOfSol(n-2) + numOfSol(n-3);
    return ret;
}

int main() {
    int T, n;
    memset(cache, 0, sizeof(cache));
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        scanf("%d", &n);
        printf("%d\n", numOfSol(n));
    }
    return 0;
}
