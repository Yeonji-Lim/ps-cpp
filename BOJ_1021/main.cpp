#include <cstdio>

int main() {
    int N, M, cur = 1, des, result = 0, temp;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++) {
        scanf("%d", &des);
        if(des == cur) {

        }
        temp = des > cur? des - cur: cur - des;
        if(temp > N / 2) temp = N - temp;
        result += temp;
        cur = des;
    }
    printf("%d\n", result);
}
