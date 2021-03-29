#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int n = 0, i, j;
    bool isPrime[1000001];

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
        for(i = 3; i < n/2; i++) {
            if(isPrime[i] && isPrime[n-i]) {
                printf("%d = %d + %d\n", n, i, n-i);
                break;
            }
        }
        if(i == n/2) {
            printf("Goldbach's conjecture is wrong.\n");
        }
        scanf("%d", &n);
    }
    return 0;
}
