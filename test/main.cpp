#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    pair<int, string> nums = {make_pair(0, "zero"), };
    string strs[10] = {"zero", "one", "two"};
    cout << strs[1] << endl;
    for(int i = 0; i < 2; i++) {
        if(strs[i] == "one") {
            cout << i << endl;
        }
    }
    string tmp;
    for(int i = 1; i < 4; i++) {
        tmp = strs[1].substr(0, i);
        cout << tmp << endl;
        for(int j = 0; j < 3; j++) {
            if(tmp == strs[j]) {
                cout << "answer tmp = " << tmp << " j = " << j << endl;
            }
        }
    }
    tmp = "1";
    int num = (int)(tmp[0]-'0');
    cout << num << endl;
    tmp = "TEST";
    if(tmp[1] == 'E') cout << "okay" << endl;

    vector<vector<string>> bigV;
    vector<string> smlV;
    smlV.push_back("firstfirst");
    smlV.push_back("firstsecond");
    bigV.push_back(smlV);
    smlV.clear();
    smlV.push_back("secondfirst");
    smlV.push_back("secondsecond");
    bigV.push_back(smlV);
    smlV.clear();
    smlV.assign(bigV[1].begin(), bigV[1].end());
    for(int i = 0; i < 2; i++) {
        cout << smlV[i] << endl;
    }
    cout << smlV[1][2] << endl;

    return 0;
}
