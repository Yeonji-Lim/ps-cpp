#include <cstdio>
#include <cstring>
int cache[1001];

int tiling2(int n) {
    int & rst = cache[n];
    if(rst != 0) return rst;
    rst = (tiling2(n-1) + 2*tiling2(n-2)) % 10007;
    return rst;
}

int main() {
    int n;
    scanf("%d", &n);
    memset(cache, 0, sizeof(cache));
    cache[1] = 1;
    cache[2] = 3;
    printf("%d", tiling2(n));
}