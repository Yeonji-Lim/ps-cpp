#include <cstdio>

int main() {
    char str[101];
    scanf("%s", str);

    for(int i = 0; i < 101; i++) {
        if(str[i] == '\0') break;
        printf("%c", str[i]);
        if((i+1)%10 == 0) printf("\n");
    }
    return 0;
}