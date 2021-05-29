//#include <cstdio>
//int n;
//int A[1001] = {1, 1};
//
//int main() {
//    scanf("%d", &n);
//    for(int i=2; i<n+1; i++) {
//        A[i] = (A[i-1] + A[i-2]) % 10007;
//    }
//    printf("%d", A[n]);
//    return 0;
//}

#include <cstdio>
#include <cstring>

int cache[1000];

int tiling(int n) {
    if(cache[n] != 0) return cache[n];
    int & result = cache[n];
    result = (tiling(n-1) + tiling(n-2)) % 10007;
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    memset(cache, 0, sizeof(cache));
    cache[1] = 1;
    cache[2] = 2;
    printf("%d", tiling(n));
    return 0;
}


























