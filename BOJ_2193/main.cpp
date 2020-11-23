#include <cstdio>
int n;
long long int A[91] = {0, 1};

int main() {
    scanf("%d", &n);
    for(int i=2; i<n+1; i++) {
        A[i] = A[i-1] + A[i-2];
    }
    printf("%lld", A[n]);
    return 0;
}
