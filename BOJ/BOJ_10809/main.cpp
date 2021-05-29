#include <cstdio>
#include <cstring>

int main() {
    int a[26], i;
    memset(a, -1, sizeof(a));
    char s[100];
    scanf("%s", s);
    for(i = 0; s[i] != '\0'; i++) {
        if(a[s[i]-97] == -1) a[s[i]-97] = i;
    }
    for(i = 0; i < 26; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
