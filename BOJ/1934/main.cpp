/* 2021.3.23 Solved - 1116KB 136ms */
#include <cstdio>

int main() {
    int t, a, b, rst;
    scanf("%d", &t);
    while(t) {
        scanf("%d %d", &a, &b);
        for(rst = a < b? a: b; rst > 0; rst--) {
            if(a%rst == 0 && b%rst == 0) {
                rst *= a/rst*b/rst;
                break;
            }
        }
        printf("%d\n", rst);
        t--;
    }
    return 0;
}