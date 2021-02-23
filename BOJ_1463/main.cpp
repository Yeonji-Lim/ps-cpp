/* 1차 성공
#include <cstdio>
using namespace std;
int N;
int A[1000001];

int min(int a, int b) {
    return a > b? b: a;
}

void calculate(int n) {
    if(n<4) return;
    for(int i=3; i<n+1; i++) {
        int rst = A[i-1] + 1;
        if(i%3 == 0) {
            rst = min(rst, A[i/3] + 1);
        }
        if(i%2 == 0) {
            rst = min(rst, A[i/2] + 1);
        }
        A[i] = rst;
    }
}

int main() {
    scanf("%d", &N);
    A[2] = 1;
    A[3] = 1;
    calculate(N);
    printf("%d", A[N]);
    return 0;
}
 */

#include <cstdio>
#include <cstring>
#define MAX 1000001

int count = 0;
int cache[MAX];

int min(int a, int b) { return a > b? b : a; }

int makeOne (int N) {
    if( N == 1 ) return 0;
    int ret = MAX;

    if(N%3 == 0) {
        if(cache[N/3] != -1) {
            ret = min(ret, cache[N/3]) + 1;
        } else {
            ret = min(ret, makeOne(N/3)) + 1;
        }
    }

    if(N%2 == 0) {
        if(cache[N/2] != -1) {
            ret = min(ret, cache[N/2]) + 1;
        } else {
            ret = min(ret, makeOne(N/2)) + 1;
        }
    }

    if(cache[N-1] != -1) {
        ret = min(ret, cache[N-1]) + 1;
    } else {
        ret = min(ret, makeOne(N-1)) + 1;
    }

    cache[N] = ret;
    return cache[N];
}

int main() {
    int N;
    scanf("%d", &N);
    memset(cache, -1, sizeof(cache));
    cache[1] = 0;
    int result = makeOne(N);
    printf("%d", result);
    return 0;
}