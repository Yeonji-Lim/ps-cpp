/* 2021.3.20 Solved - 1116KB 0ms */
#include <cstdio>

int main() {
    char s[100];
    int i, a[26] = {0};
    scanf("%s", s);
    for(i = 0; s[i] != '\0'; i++) {
        a[s[i]-97]++;
    }
    for(i = 0; i < 26; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
