#include <cstdio>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    while(A>0 && A<10) {
        printf("%d\n", A + B);
        A = 0;
        scanf("%d %d", &A, &B);
    }
    return 0;
}