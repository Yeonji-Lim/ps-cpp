#include <cstdio>
int P,N,M;

int main() {
    scanf("%d",&P);
    while(P--){
        scanf("%d %d", &N, &M);
        int one = 1;
        int two = 1;
        int cnt = 0;
        while(true) {
            int tmp = one + two;
            one = two;
            two = tmp % M;
            cnt++;
            if(one == 1 && two == 1) break;
        }
        printf("%d %d\n", N, cnt);
    }
    return 0;
}
