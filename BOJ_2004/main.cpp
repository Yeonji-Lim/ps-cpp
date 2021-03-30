#include <cstdio>

int main() {
    int n, m, rst = 0, mcnt, tmp, mncnt, i;
    scanf("%d %d", &n, &m);
    if(m == 0 || m == n || n < 5) { printf("0\n"); return 0;}
    for(i = 5; i <= n; i++) {
        tmp = i;
        while(tmp%5 == 0) {
            ++rst;
            tmp /= 5;
        }
        if(i == m) mcnt = rst;
        if(i == n-m) mncnt = rst;
    }
    printf("%d\n", rst-mcnt-mncnt);
    return 0;
}
