#include <iostream>

using namespace std;

bool vst[10001] = {false};

int d(int n) {
    int rst = n, tmp = n;
    while(tmp) {
        rst += tmp%10;
        tmp /= 10;
    }
    return rst;
}

int main() {
    ios_base::sync_with_stdio(0);
    int ni = 0;
    for(int i = 1; i < 10001; i++) {
        if(!vst[i]) cout << i << '\n';
        ni = d(i);
        if(ni < 10001) vst[ni] = true;
    }
    return 0;
}