/* 2021.3.23 Solved - 1116KB 0ms */
#include <cstdio>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n%d\n%d\n%d", (a+b)%c, (a+b)%c, (a*b)%c, (a*b)%c);
    return 0;
}
