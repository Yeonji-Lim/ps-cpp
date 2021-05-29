/* 2021.3.30 Solved - 1116KB 0ms */
#include <cstdio>

int min(int a, int b) { return a < b? a: b; }

int countFive(int n) {
    int ret = 0;
    while(n/5 != 0) {
        n /= 5;
        ret += n;
    }
    return ret;
}

int countTwo(int n) {
    int ret = 0;
    while(n/2 != 0) {
        n /= 2;
        ret += n;
    }
    return ret;
}

int main() {
    int n, m, five = 0, two = 0;
    scanf("%d %d", &n, &m);
    if(m == 0 || m == n || n < 5) { printf("0\n"); return 0;}
    five = countFive(n)-countFive(m)-countFive(n-m);
    two = countTwo(n)-countTwo(m)-countTwo(n-m);
    printf("%d\n", min(five, two));
    return 0;
}