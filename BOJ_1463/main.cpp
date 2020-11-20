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