#include <cstdio>

int GCD(int a, int b) {
    if(a%b == 0) return b;
    return GCD(b, a%b);
}

int main() {
    int t, n, rst = 0;
    int a[100];
    scanf("%d", &t);
    while(t) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                rst += GCD(a[i], a[j]);
            }
        }
        printf("%d\n", rst);
        rst = 0;
        t--;
    }
    return 0;
}