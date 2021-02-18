#include <cstdio>

int main() {
    int T, R = 0, N[100];
    char ch;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        scanf("%1d", &N[i]); // 공백없이 숫자 하나씩 입력 받음
        R += N[i];
    }
    printf("%d", R);
    return 0;
}