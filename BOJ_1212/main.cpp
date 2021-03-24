#include <cstdio>
#include <vector>
using namespace std;

int octalToBinary(int a) {
    int ret = 0, tmp = 1;
    for(int i = 0; i < 3; i++) {
        ret += a%2*tmp;
        tmp *= 10;
        a /= 2;
    }
    return ret;
}

int main() {
    vector<char> n;
    vector<int> rst;
    char c;
    scanf("%c", &c);
    while(c != '\n') {
        n.push_back(c);
        scanf("%c", &c);
    }
    for(int i = rst.size()-1; i > -1; i--) {
        rst.push_back(octalToBinary(n[i]-'0'));
    }
    for(int i = rst.size()-1; i > -1; i--) {
        if(i = rst.size()-1) {
            printf("%d", rst[i]);
            continue;
        }
        if(rst[i]/10 == 0) {
            printf("00%d", rst[i]);
        } else if (rst[i]/100 == 0) {
            printf("0%d", rst[i]);
        } else {
            printf("%d", rst[i]);
        }
    }
    return 0;
}
