/* 2021.3.5 Solved - 1116KB 0ms */
#include <cstdio>
#define MAX 101
long long int dp[MAX] = {0,1,1,1,2,2,};

long long int pado(int n) {
    long long int & ret = dp[n];
    if(ret != 0) return ret;
    ret = pado(n-5) + pado(n-1);
    return ret;
}

int main() {
    int t, n;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%lld\n", pado(n));
    }
    return 0;
}
