#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int n, i, j;
    vector<bool> isPrime(10000001);
    isPrime[0] = false;
    isPrime[1] = false;
    for(i = 2; i < 10000001; i++) { isPrime[i] = true; }
    for(i = 2; i < sqrt(10000000); i++) {
        for(j = i*2; j < 10000001; j += i) {
            isPrime[j] = false;
        }
    }
    scanf("%d", &n);
    if(n == 1) { return 0; }
    i = 2;
    while(!isPrime[n]) {
        if(n%i == 0) {
            n /= i;
            printf("%d\n", i);
            continue;
        }
        do { ++i; } while(!isPrime[i]);
    }
    printf("%d\n", n);
    return 0;
}
