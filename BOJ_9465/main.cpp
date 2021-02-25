#include <cstdio>
#include <cstring>
#include <cstdlib>
#define ARR_SIZE 100001
#define STR_SIZE 500000
int DP[ARR_SIZE][3];
int sti[2][ARR_SIZE];
char str[STR_SIZE];

void sticker(int n) {
    if(DP[n][0] != -1) return;
    if(DP[n-1][0] == -1) sticker(n-1);
    DP[n][0] = DP[n-1][1] + DP[n-1][2] + sti[0][n];
    DP[n][1] = DP[n-1][0] + DP[n-1][2] + sti[1][n];
    DP[n][2] = DP[n-1][0] + DP[n-1][1] + DP[n-1][2];
    return;
}

int main() {
    int t, n, i, j, tmp;
    char* score_ch;
    scanf("%d", &t);
    for(i = 0; i < t; i++) {
        scanf("%d", &n);

        for(j = 2; j < ARR_SIZE; j++) {
            memset(DP[j], -1, sizeof(DP[0]));
        }
        memset(sti[0], -1, sizeof(sti[0]));
        memset(sti[1], -1, sizeof(sti[1]));

        for(int k = 0; k < 2; k++) {
            for(j = 1; j <= n; j++) {
                scanf("%d", &tmp);
                sti[k][j] = tmp;
            }
        }

        DP[1][0] = sti[0][1];
        DP[1][1] = sti[1][1];
        DP[1][2] = 0;

        for(int k = 0; k < 2; k++) {
            printf("\n");
            for(j = 1; j <= n; j++) {
                printf("%d ", sti[k][j]);
            }
        }
        printf("\n");

        sticker(n);

        tmp = DP[n][0] > DP[n][1] ? DP[n][0] : DP[n][1];
        tmp = tmp > DP[n][2] ? tmp : DP[n][2];
        printf("%d\n", tmp);
    }
    return 0;
}
