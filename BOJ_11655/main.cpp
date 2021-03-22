#include <cstdio>

int main() {
    char s[101];
    char c;
    scanf("%[^\n]s", s);
    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == ' ' || (s[i] > 47 && s[i] < 58)) { printf("%c", s[i]); }
        else {
            c = s[i]+13;
            if(s[i] > 64 && s[i] < 91 && c > 90) {
                c = 'A' + (c - 'Z') - 1;
            } else if(s[i] > 96 && s[i] < 123 && c > 122){
                c = 'a' + (c - 'z') - 1;
            }
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}
