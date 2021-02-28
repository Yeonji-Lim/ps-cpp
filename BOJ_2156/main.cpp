#include <cstdio>
#include <cstring>
#define ARR_SIZE 10001
int score[ARR_SIZE];
int DP[ARR_SIZE][4];

int max (int a, int b) { return a > b? a: b; }

void drinkingWine (int n) {
    if(DP[n][0] != -1) return;
    if(DP[n-1][0] == -1) {
        drinkingWine(n-1);
    }
    DP[n][0] = DP[n-1][2] + score[n];
    DP[n][1] = max(DP[n-1][0], DP[n-1][2]);
    DP[n][2] = max(DP[n-1][1] + score[n], DP[n-1][3] + score[n]);
    DP[n][3] = max(DP[n-1][1], DP[n-1][3]);
    return;
}

int main() {
    int n, i, tmp;
    memset(score, -1, sizeof(score));
    for(i = 0; i < ARR_SIZE; i++) {
        memset(DP[i], -1, sizeof(DP[0]));
    }
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        scanf("%d", &tmp);
        score[i] = tmp;
    }
    if(n == 1) {
        printf("%d\n", score[1]);
    } else if (n == 2) {
        printf("%d\n", score[1] + score[2]);
    } else {
        DP[2][0] = score[1] + score[2];
        DP[2][1] = score[1];
        DP[2][2] = score[2];
        DP[2][3] = 0;
        drinkingWine(n);
        tmp = max(DP[n][0], DP[n][1]);
        tmp = max(tmp, DP[n][2]);
        tmp = max(tmp, DP[n][3]);
        printf("%d\n", tmp);
    }
    return 0;
}
