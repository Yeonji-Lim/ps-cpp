#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    char inputStr[100];
    scanf("%[^\n]s", inputStr); //공백까지 입력 받고 싶은 경우에는 이렇게
    while(!strcmp(inputStr, " ")){
        printf("%s\n", inputStr);
        strcpy(inputStr, " ");
        scanf("%[^\n]s", inputStr);
    }
    return 0;
}