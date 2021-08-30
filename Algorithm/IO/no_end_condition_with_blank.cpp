#include <iostream>
#include <vector>
using namespace std;

bool chli_to_ili(char chli[], vector<int>& ili) {
    int tmp = 0, cnt = 0;
    for (int i = 0; cnt < 40 && chli[i]; i++) {
        if (chli[i] != ' ') {
            tmp = tmp * 10 + chli[i] - '0';
        }
        else if (tmp > 0) {
            ili.push_back(tmp);
            tmp = 0;
            cnt++;
        } else { return false; }
    }
    return true;
}