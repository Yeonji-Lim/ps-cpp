/* 2021.3.22 Solved - 1124KB 0ms */
#include <cstdio>
#include <cstring>

long long int strToLLInt (char s[]) {
    long long int ret = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if(i != 0) ret *= 10;
        ret += s[i]-'0';
    }
    return ret;
}

int main() {
    long long int rst;
    char s[4][13];
    scanf("%s %s %s %s", s[0], s[1], s[2], s[3]);
    strcat(s[0], s[1]);
    strcat(s[2], s[3]);
    rst = strToLLInt(s[0]);
    rst += strToLLInt(s[2]);
    printf("%lld\n", rst);
    return 0;
}
