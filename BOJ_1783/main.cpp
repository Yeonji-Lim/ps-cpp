/* 2021.5.29 Solved - 1116KB 0ms */
#include <cstdio>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    if(n == 1) printf("1\n");
    else if(n == 2) printf("%d\n", m > 6? 4: (m-1)/2+1);
    else if(m < 7) printf("%d\n", m > 3? 4: m);
    else printf("%d\n", m-2);

    return 0;
}