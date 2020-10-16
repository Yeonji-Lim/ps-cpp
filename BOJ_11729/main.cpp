#include <iostream>
#include <math.h>
using namespace std;

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
    printf("%d\n", (int)(pow(2, num)-1));
    TowerOfHanoi(1, 3, 2, num);
    return 0;
}
