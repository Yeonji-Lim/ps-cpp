//#include <cstdio>
//int n;
//long long int A[91] = {0, 1};
//
//int main() {
//    scanf("%d", &n);
//    for(int i=2; i<n+1; i++) {
//        A[i] = A[i-1] + A[i-2];
//    }
//    printf("%lld", A[n]);
//    return 0;
//}

// 2021.2.25
#include <cstdio>
#include <cstring>
int cache[91][2];

void bimaryNumber(int n) {
    if(cache[n][0] != -1) return;
    if(cache[n-1][0] == -1) {
        bimaryNumber(n-1);
    }
    cache[n][0] = cache[n-1][0] + cache[n-1][1];
    cache[n][1] = cache[n-1][0];
    return;
}

int main() {
    int n;
    for(int i = 0; i < 91; i++) {
        memset(cache[i], -1, sizeof(cache[i]));
    }
    cache[1][0] = 0;
    cache[1][1] = 1;
    scanf("%d", &n);
    bimaryNumber(n);
    printf("%d", cache[n][0] + cache[n][1]);
    return 0;
}

