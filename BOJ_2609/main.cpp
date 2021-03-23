/* 2021.3.23 Solved - 1116KB 0ms */
#include <cstdio>

int main() {
    int a, b;
    int c, d;
    scanf("%d %d", &a, &b);
    for(c = a < b? a: b; c > 0; c--) {
        if(a%c == 0 && b%c == 0) {
            d = c*a/c*b/c;
            break;
        }
    }
    printf("%d\n%d\n", c, d);
    return 0;
}