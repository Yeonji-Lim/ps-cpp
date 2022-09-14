/* 2021.5.11 Solved - 1116KB 340ms */
#include <cstdio>

void printStar(int n, int i) {
    if(n == 3) {
        if(i == 0) printf("  *  ");
        else if(i == 1) printf(" * * ");
        else printf("*****");
        return;
    }
    if(i < n/2) {
        for(int j = 0; j < n/2; j++) printf(" ");
        printStar(n/2, i);
        for(int j = 0; j < n/2; j++) printf(" ");
    } else {
        i -= n/2;
        printStar(n/2, i);
        printf(" ");
        printStar(n/2, i);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printStar(n, i);
        printf("\n");
    }
    return 0;
}