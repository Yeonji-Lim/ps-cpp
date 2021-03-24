#include <cstdio>
int binaryToOctal(int a) {
    int ret = 0, tmp = 1;
    while(a != 0) {
        ret += (a%10 + (a%100-a%10)/10*2 + (a%1000-a%100)/100*4)*tmp;
        tmp *= 10;
        a /= 1000;
    }
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", binaryToOctal(n));
    return 0;
}