/* 2021.3.22 Solved - 1116KB 0ms */
#include <cstdio>

int main() {
    char s[101];
    scanf("%[^\n]s", s);
    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == ' ' || (s[i] > 47 && s[i] < 58)) { printf("%c", s[i]); }
        else if((s[i] > 64 && s[i] < 91 && s[i]+13 > 90) || (s[i] > 96 && s[i] < 123 && s[i]+13 > 122)) {
            printf("%c", s[i]-13);
        } else {
            printf("%c", s[i]+13);
        }
    }
    printf("\n");
    return 0;
}
