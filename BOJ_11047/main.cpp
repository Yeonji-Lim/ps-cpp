#include <cstdio>
int main() {
    int n, k, a=0;
    int A[10];
    scanf("%d %d",&n,&k);
    for(int i=0; i<n; i++) {
        scanf("%d",&A[i]);
    }
    for(int j=n-1; j>=0; j--) {
        a+=k/A[j];
        k%=A[j];
    }
    printf("%d",a);
    return 0;
}
