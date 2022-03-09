#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isNum(char t) { return t >= '0' && t <= '9'; }
bool cmp(char x, char y) {
    if(isNum(x)) {
        if(isNum(y)) return x < y;
        else return false;
    } else if(isNum(y)) return true;
    else return x < y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s = "", tmp;
    int num = 0;
    cin >> tmp;
    for(int i = 0; i < tmp.length(); i++) {
        if(isNum(tmp[i])) num += tmp[i]-'0';
        else s+=tmp[i];
    }
    sort(s.begin(), s.end());
    if(num != 0) s += to_string(num);
    cout << s << "\n";
    return 0;
}