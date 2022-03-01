/* 2021.3.29 Solved - 1968KB 40ms */
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int n = 0, i, j;
    bool isPrime[1000001];
    isPrime[1] = false;
    for(i = 2; i < 1000001; i++) {
        isPrime[i] = true;
    }

    for(i = 2; i < sqrt(1000000); i++) {
        for(j = i*2; j < 1000001; j += i) {
            isPrime[j] = false;
        }
    }

    scanf("%d", &n);
    while(n != 0) {
        for(i = 3; i < n/2 + 1; i += 2) {
            if(isPrime[i] && isPrime[n-i]) {
                printf("%d = %d + %d\n", n, i, n-i);
                break;
            }
        }
        if(i == n/2 + 1) {
            printf("Goldbach's conjecture is wrong.\n");
        }
        scanf("%d", &n);
    }
    return 0;
}
