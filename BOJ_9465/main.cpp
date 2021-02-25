#include <cstdio>
#include <cstring>
#define ARR_SIZE 100001
int DP[ARR_SIZE][3];
int sti[2][ARR_SIZE];

void sticker(int n) {
    if(DP[n][0] != -1) return;
    if(DP[n-1][0] == -1) sticker(n-1);
    DP[n][0] = DP[n-1][1] + DP[n-1][2] + sti[0][n];
    DP[n][1] = DP[n-1][0] + DP[n-1][2] + sti[1][n];
    DP[n][2] = DP[n-1][0] + DP[n-1][1] + DP[n-1][2];
    return;
}

int main() {
    int n;
    for(int i = 0; i < 10; i++) {
        scanf("%d", &n);
        printf("%d\n", n);
    }

//    int t, n, i, j, rst;
//    scanf("%d", &t);
//    for(i = 0; i < t; i++) {
//        scanf("%d", &n);
//
//        for(j = 2; j < ARR_SIZE; j++) {
//            memset(DP[j], -1, sizeof(DP[0]));
//        }
//        memset(sti[0], -1, sizeof(sti[0]));
//        memset(sti[1], -1, sizeof(sti[1]));
//
//        for(j = 1; j <= n; j++) {
//            scanf("%d", sti[0][j]);
//        }
//        for(j = 1; j <= n; j++) {
//            scanf("%d", sti[1][j]);
//        }
//
//        DP[1][0] = sti[0][1];
//        DP[1][1] = sti[1][1];
//        DP[1][2] = 0;
//
//        printf("%d %d %d", DP[2][0], sti[0][1], sti[1][1]);
//        sticker(n);
//
//        rst = DP[n][0] > DP[n][1]? DP[n][0] : DP[n][1];
//        rst = rst > DP[n][2]? rst : DP[n][2];
//        printf("%d\n", rst);
//    }
    return 0;
}
