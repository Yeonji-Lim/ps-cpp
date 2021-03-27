#include <cstdio>

bool isPrimeNumber (int a) {
    if(a == 1) return false;
    for(int i = 2; i < a; i++) {
        if(a%i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, a[100], rst = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(isPrimeNumber(a[i])) ++rst;
    }
    printf("%d", rst);
    return 0;
}
