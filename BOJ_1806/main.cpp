#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, S;

int main() {
    scanf("%d %d", &N, &S);
    vector<int> V(N, 0);
    for(int i=0; i<N; i++) {
        scanf("%d", &V[i]);
    }
    queue<int> Q;
    int sum = 0, ans = N+1;
    for(int i=0; i<N; i++) {
        Q.push(V[i]);
        sum+=V[i];
        if(sum > S) {
            while(sum-Q.front() > S) {
                sum-=Q.front();
                Q.pop();
            }
            if(Q.size() < ans) ans = Q.size();
        }
    }
    ans == N+1? printf("0"): printf("%d", ans);
    return 0;
}
