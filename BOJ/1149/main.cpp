#include <cstdio>
#include <algorithm>
using namespace std;
int N;
int A[1001][3];

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
    }
    for(int i=2; i<=N; i++) {
        A[i][0] += min(A[i-1][1], A[i-1][2]);
        A[i][1] += min(A[i-1][0], A[i-1][2]);
        A[i][2] += min(A[i-1][1], A[i-1][0]);
    }
    int ans = min(A[N][0], A[N][1]);
    ans = min(ans, A[N][2]);
    printf("%d", ans);

    return 0;
}
