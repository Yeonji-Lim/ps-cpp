#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i < 2*N; i++) {
        if(i <= N) {
            for(int j = 0; j < i; j++) {
                printf("*");
            }
            for(int j = 0; j < 2*(N-i); j++) {
                printf(" ");
            }
            for(int j = 0; j < i; j++) {
                printf("*");
            }
        } else {
            for(int j = 0; j < 2*N-i; j++) {
                printf("*");
            }
            for(int j = 0; j < 2*(i-N); j++) {
                printf(" ");
            }
            for(int j = 0; j < 2*N-i; j++) {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}