/* 모범답안 */
#include <cstdio>

int main() {
    int n, k, rst = 0;
    scanf("%d %d", &n, &k);
    while(n != 1){
        // 1 빼기 때문에 반복을 돌지 않아도 됨
        rst += n%k;
        n -= n%k;
        if(n < k) break;
        rst++;
        n /= k;
    }
    printf("%d", rst);
    return 0;
}

/* 2021.5.29 */
/* 1이 될 때까지 */
//#include <cstdio>
//
//int main() {
//    int n, k, rst = 0;
//    scanf("%d %d", &n, &k);
//    while(n != 1) {
//        if(n%k == 0) n /= k;
//        else n -= 1;
//        rst++;
//    }
//    printf("%d", rst);
//    return 0;
//}
