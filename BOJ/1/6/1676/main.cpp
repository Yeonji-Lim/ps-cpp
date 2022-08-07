/* 2021.3.30 Solved - 1116KB 0ms */
#include <cstdio>

int main() {
    int n, tmp = 24, rst = 0;
    scanf("%d", &n);
    if(n < 5) { printf("0\n"); return 0;}
    for(int i = 5; i <= n; i++) {
        tmp *= i;
        while(tmp%10 == 0) {
            ++rst;
            tmp /= 10;
        }
        tmp %= 1000; //왜 100은 안되고 1000만 되는 지에 대한 반례는 못 찾음.
    }
    printf("%d\n", rst);
    return 0;
}