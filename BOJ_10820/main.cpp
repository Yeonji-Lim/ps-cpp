#include <cstdio>

int main() {
    int n, a[4] = {0};
    char s[100];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%[^\n]", s);
        for(int j = 0; s[j] != '\0'; j++) {
            if(s[j] == ' ') { a[3]++; }
            else if(s[j] > 47 && s[j] < 58) { a[2]++; }
            else if (s[j] > 64 && s[j] < 92) { a[1]++; }
            else if (s[j] > 96 && s[j] < 124) { a[0]++; }
        }
        printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]);
    }
    return 0;
}
