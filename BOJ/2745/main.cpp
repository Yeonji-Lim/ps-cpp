/* 2021.3.23 Solved - 2016KB 0ms */
#include <iostream>
using namespace std;

int charToInt (char c) {
    int ret;
    if(c >= 'A') { ret = (c - 'A') + 10; }
    else { ret = c - '0'; }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string n;
    int b, rst = 0, a = 1;
    cin >> n >> b;
    for(int i = n.length()-1; i > -1; i--) {
        rst += charToInt(n[i])*a;
        a *= b;
    }
    cout << rst;
    return 0;
}
