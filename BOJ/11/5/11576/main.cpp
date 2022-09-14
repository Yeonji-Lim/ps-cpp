/* 2021.3.27 Solved - 1116KB 0ms */
#include <cstdio>
int A, B, m, a[25];

int aToDecimal() {
    int ret = 0, tmp = 1;
    for(int i = m-1; i > -1; i--) {
        ret += a[i]*tmp;
        tmp *= A;
    }
    return ret;
}

void decimalToB(int d) {
    int i = 0;
    while(d != 0) {
        a[i] = d%B;
        d /= B;
        i++;
    }
    i--;
    while(i > -1) {
        printf("%d ", a[i]);
        i--;
    }
    printf("\n");
    return;
}

int main() {
    int i;
    scanf("%d %d", &A, &B);
    scanf("%d", &m);
    for(i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }
    decimalToB(aToDecimal());
    return 0;
}
