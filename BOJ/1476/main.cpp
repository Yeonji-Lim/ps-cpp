/* 2021.6.8 Solved - 1112KB 0ms */
#include <cstdio>

int main() {
    int e, s, m, te = 1, ts = 1, tm = 1, rst = 1;
    scanf("%d %d %d", &e, &s, &m);
    while(!(te == e && ts == s && tm == m)) {
        if(++te == 16) te = 1;
        if(++ts == 29) ts = 1;
        if(++tm == 20) tm = 1;
        rst++;
    }
    printf("%d", rst);
    return 0;
}