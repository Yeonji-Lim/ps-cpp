/* Failed */
//#include <vector>
//#include <climits>
//#define INF INT_MIN
//using namespace std;
//vector<int> S;
//vector<vector<int>> D;
//int max(int a, int b) { return a>b? a: b; }
//
//int findMax(int i, int cnt){
//    if(i < 0 || cnt == 2) return INF; // 0을 넘어가거나, 연속으로 3개의 계단을 밟으려고 할 경우
//    if(D[i][cnt] != -1) return D[i][cnt]; // 이미 겪은 경우
//    D[i][cnt] = S[i] + max(findMax(i - 1, cnt+1), findMax(i - 2, 0));
//    return D[i][cnt];
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);
//    S.resize(n, 0);
//    D.resize(n, vector<int>(2, -1)); // 모든 값을 -1로 바꿔줌
//    for(int i=0; i<n; i++) scanf("%d", &S[i]);
//    // 0의 위치에서의 점수 미리 넣어줌
//    D[0][0] = S[0];
//    D[0][1] = S[0];
//    // 0부터 시작이니까 n-1번째꺼 출력
//    printf("%d", findMax(n-1, 0));
//    return 0;
//}

/* 2021.3.1 Failed : 연속 3개 고려안함 */
//#include <cstdio>
//#include <cstring>
//#define MAX 301
//int dp[MAX];
//int score[MAX];
//
//int max(int a, int b) { return a > b? a: b;}
//
//int stairs(int n) {
//    int & ret = dp[n];
//    if(ret != -1) return ret;
//    ret = max(stairs(n-1), stairs(n-2)) + score[n];
//    return ret;
//}
//
//int main() {
//    int n, i, tmp;
//    memset(dp, -1, sizeof(dp));
//    scanf("%d", &n);
//    for(i = 1; i <= n; i++) {
//        scanf("%d", &tmp);
//        score[i] = tmp;
//    }
//    dp[1] = score[1];
//    dp[2] = score[1] + score[2];
//    printf("%d\n", stairs(n));
//    return 0;
//}

/* */
#include <cstdio>
#include <cstring>
#define MAX 301
int dp[MAX][3];
short int score[MAX];
int max(int a, int b) { return a > b? a: b; }

void stairs(int n) {
    if(dp[n][0] != -1) return;
    if(dp[n-1][0] == -1) stairs(n-1);
    dp[n][0] = dp[n-1][2] + score[n];
    dp[n][1] = max(dp[n-1][0], dp[n-1][2]);
    dp[n][2] = dp[n-1][1] + score[n];
    return;
}

int main() {
    int n, i, tmp;
    for(i = 0; i < MAX; i++) {
        memset(dp[i], -1, sizeof(dp[0]));
    }
    memset(score, -1, sizeof(score));
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        scanf("%d", &tmp);
        score[i] = tmp;
    }
    dp[1][0] = score[1];
    dp[1][1] = 0;
    dp[1][2] = score[1];
    stairs(n);
    tmp = max(dp[n][0], dp[n][2]);
    printf("%d\n", tmp);
    return 0;
}