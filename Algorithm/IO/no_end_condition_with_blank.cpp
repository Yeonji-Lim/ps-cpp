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
    ili.push_back(tmp);
    return true;
}

bool str_to_ili(string str, vector<int> &ili) {
    int tmp = 0, cnt = 0;
    for (int i = 0; cnt < 40 && str[i]; i++) {
        if (str[i] != ' ') {
            tmp = tmp * 10 + str[i] - '0';
        }
        else if (tmp > 0) {
            ili.push_back(tmp);
            tmp = 0;
            cnt++;
        }
        else { return false; }
    }
    ili.push_back(tmp);
    return true;
}

int main() {
    char chli[40];
    cin.getline(chli, 40);

    string str;
    getline(cin, str);

    return 0;
}