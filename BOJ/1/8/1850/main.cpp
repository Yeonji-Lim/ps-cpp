/* 2021.3.23 Solved - 1116KB 92ms */
#include <cstdio>

long long GCD(long long a, long long b) {
    if(a%b == 0) return b;
    return GCD(b, a%b);
}

int main() {
    long long a, b, rst;
    scanf("%lld %lld", &a, &b);
    rst = GCD(a, b);
    while(rst) {
        printf("1");
        rst--;
    }
    return 0;
}