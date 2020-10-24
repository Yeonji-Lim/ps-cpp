#include <cstdio>
int main() {
    long long S, sum = 0;
    int N = 1;
    scanf("%lld", &S);
    while(true) {
        sum += N;
        if(sum > S) {
            N--;
            break;
        }
        N++;
    }
    printf("%d", N);
    return 0;
}