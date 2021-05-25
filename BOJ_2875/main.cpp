/* 2021.5.25 Solved - 1112KB 0ms */
#include <cstdio>

int main() {
    int n, m, k, rst;
    scanf("%d %d %d", &n, &m, &k);
    rst = n/2 < m ? n/2 : m;
    k -= n-rst*2 + m-rst;
    if(k > 0) printf("%d\n", rst - (k-1)/3 - 1);
    else printf("%d\n", rst);
    return 0;
}