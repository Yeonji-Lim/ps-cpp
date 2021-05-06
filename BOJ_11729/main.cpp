//#include <iostream>
//#include <math.h>
//using namespace std;
//
//void TowerOfHanoi(int src, int dst, int tmp, int num) {
//    if(num == 1) {
//        printf("%d %d\n", src, dst);
//        return;
//    }
//    TowerOfHanoi(src, tmp, dst, num - 1);
//    TowerOfHanoi(src, dst, tmp, 1);
//    TowerOfHanoi(tmp, dst, src, num - 1);
//    return;
//}
//
//
//int main() {
//    int num;
//    cin >> num;
//    printf("%d\n", (int)(pow(2, num)-1));
//    TowerOfHanoi(1, 3, 2, num);
//    return 0;
//}

/* 2021.5.6 Solved - 1300KB 148ms */
#include <cstdio>
#include <cmath>

void hanoiTower(int n, int a, int c, int b) {
    if(n == 1) {
        printf("%d %d\n", a, c);
        return;
    }
    hanoiTower(n-1, a, b, c);
    printf("%d %d\n", a, c);
    hanoiTower(n-1, b, c, a);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", (int)pow(2, n) - 1);
    hanoiTower(n, 1, 3, 2);
    return 0;
}