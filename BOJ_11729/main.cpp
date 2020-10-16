#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//                   출발지,    목적지,   나머지, 이동할 판의 개수
void TowerOfHanoi(int src, int dst, int tmp, int num) {
    if(num == 1) {
        printf("%d %d\n", src, dst);
        return;
    }
    TowerOfHanoi(src, tmp, dst, num - 1);
    TowerOfHanoi(src, dst, tmp, 1);
    TowerOfHanoi(tmp, dst, src, num - 1);

    return;
}


int main() {
    int num;
    cin >> num;
    // (n개의 판이 있을때 최소 이동 횟수) = 2 * (n-1개의 판이 있을 때 최소 이동 횟수) + 1
    // 즉, 점화식을 풀어야한다. An = 2*An-1 + 1 -----> An = 2^n - 1
    printf("%d\n", (int)(pow(2, num)-1));
    TowerOfHanoi(1, 3, 2, num);
    return 0;
}
