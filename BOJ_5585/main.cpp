#include <cstdio>
int N;
int ans = 0;
int main() {
    scanf("%d", &N);
    N = 1000 - N;
    if(N >= 500) {
        N -= 500;
        ans++;
    }
    while (N >= 100) {
        N -= 100;
        ans++;
    }
    while (N >= 50) {
        N -= 50;
        ans++;
    }
    while (N >= 10) {
        N -= 10;
        ans++;
    }
    while (N >= 5) {
        N -= 5;
        ans++;
    }
    while (N >= 1) {
        N -= 1;
        ans++;
    }
    printf("%d", ans);
    return 0;
}
