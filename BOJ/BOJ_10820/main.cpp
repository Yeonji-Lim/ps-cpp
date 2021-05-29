/* 2021.3.22 Solved - 1116KB 0ms */
#include <cstdio>
#include <cstring>

int main() {
    int a[4] = {0};
    char s[101] = "*";
    scanf("%[^\n]s", s);
    while(s[0] != '*') {
        getchar();
        for(int j = 0; s[j] != '\0'; j++) {
            if(s[j] == 64 || s[j] == ' ') { a[3]++; }
            else if(s[j] > 47 && s[j] < 58) { a[2]++; }
            else if (s[j] > 64 && s[j] < 91) { a[1]++; }
            else if (s[j] > 96 && s[j] < 123) { a[0]++; }
        }
        printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]);
        memset(a, 0, sizeof(a));
        s[0] = '*';
        scanf("%[^\n]s", s);
    }
    return 0;
}
