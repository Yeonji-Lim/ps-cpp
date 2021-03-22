#include <cstdio>
#include <algorithm>
using namespace std;

char * compare(char * a, char * b) {
    return a < b;
}

int main() {
    int i;
    char s[1001][1001];
    char tmp[1001];
    scanf("%s", tmp);
    for(i = 0; tmp[i] != '\0'; i++) {
        strcpy(s[i],tmp + i);
    }
    sort(s, s+i+1, compare());
    return 0;
}
