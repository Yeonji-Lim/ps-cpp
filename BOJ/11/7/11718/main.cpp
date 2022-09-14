#include <cstdio>

int main() {
    char ch;
    while(scanf("%c", &ch) != -1) { //려 임베디드 분야에서 EOF를 받았을 때 -1을 리턴
        printf("%c", ch); // & 가끔 붙여버림 정신차려
    }
    return 0;
}