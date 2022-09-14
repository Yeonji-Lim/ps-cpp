#include <cstdio>
#include <vector>
using namespace std;
int N, S;

int main() {
    scanf("%d %d", &N, &S);
    vector<int> V(N, 0);
    for(int i=0; i<N; i++) {
        scanf("%d", &V[i]);
    }
    int l = 0, h = 0;
    int sum = 0, ans = N+1;
    while(l <= h && h < N) {
        sum += V[h];
        while(sum-V[l] >= S) sum -= V[l++];
        if(sum >= S && ans > h-l+1) ans = h-l+1;
        h++;
    }
    ans == N+1? printf("0"): printf("%d", ans);
    return 0;
}
