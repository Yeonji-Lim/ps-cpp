#include <cstdio>

int main() {
    int n, m, rst = 0, mcnt = 0, tmp, five = 0, two = 0,  i;
    scanf("%d %d", &n, &m);
    if(m == 0 || m == n) { printf("0\n"); return 0;}
    if(m > n-m) m = n-m;
    for(i = 1; i <= m; i++) {
        tmp = i;
        while(tmp%5 == 0) {
            ++mcnt;
            tmp /= 5;
        }
    }
    for(i = n-m+1; i <= n; i++) {
        tmp = i;
        while(tmp%5 == 0) {
            ++five;
            tmp /= 5;
        }
        while(tmp%2 == 0) {
            ++two;
            tmp /= 2;
        }
    }
    if(two > five) rst = five;
    else rst = two;
    printf("%d\n", rst-mcnt);
    return 0;
}
