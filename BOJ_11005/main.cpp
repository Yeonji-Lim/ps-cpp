/* 2021.3.23 Solved - 1228KB 0ms */
#include <cstdio>
#include <vector>
using namespace std;

char intToChar (int a){
    char ret;
    if(a > 9) {
        ret = 'A' + a - 10;
    } else {
        ret = '0' + a;
    }
    return ret;
}

int main() {
    int n, b;
    vector<char> rst;
    scanf("%d %d", &n, &b);
    while(1){
        rst.push_back(intToChar(n%b));
        if(n/b != 0) n = n/b;
        else { break; }
    }
    for(int i = rst.size()-1; i > -1; i--) {
        printf("%c", rst[i]);
    }
    return 0;
}
