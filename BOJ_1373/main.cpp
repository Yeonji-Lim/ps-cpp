#include <cstdio>

int binaryToDecimal(int a){
    int ret = 0, tmp = 1;
    while(a != 0) {
        ret += a%10*tmp;
        tmp *= 2;
        a = a/10;
    }
    return ret;
}

int decimalToOctal(int a) {
    int ret = 0, tmp = 1;
    while(a != 0) {
        ret += a%8*tmp;
        tmp *= 10;
        a = a/8;
    }
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", decimalToOctal(binaryToDecimal(n)));
    return 0;
}