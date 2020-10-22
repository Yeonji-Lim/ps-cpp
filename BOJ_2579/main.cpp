#include <vector>
#include <climits>
#define INF INT_MIN
using namespace std;
vector<int> S;
vector<vector<int>> D;
int max(int a, int b) { return a>b? a: b; }

int findMax(int i, int cnt){
    if(i < 0 || cnt == 2) return INF; // 0을 넘어가거나, 연속으로 3개의 계단을 밟으려고 할 경우
    if(D[i][cnt] != -1) return D[i][cnt]; // 이미 겪은 경우
    D[i][cnt] = S[i] + max(findMax(i - 1, cnt+1), findMax(i - 2, 0));
    return D[i][cnt];
}

int main() {
    int n;
    scanf("%d", &n);
    S.resize(n, 0);
    D.resize(n, vector<int>(2, -1)); // 모든 값을 -1로 바꿔줌
    for(int i=0; i<n; i++) scanf("%d", &S[i]);
    // 0의 위치에서의 점수 미리 넣어줌
    D[0][0] = S[0];
    D[0][1] = S[0];
    // 0부터 시작이니까 n-1번째꺼 출력
    printf("%d", findMax(n-1, 0));
    return 0;
}
