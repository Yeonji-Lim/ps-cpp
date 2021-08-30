//#include <iostream>
//#include <string>
//#include <cstdio>
//#include <vector>
//using namespace std;
//
//int main() {
//    pair<int, string> nums = {make_pair(0, "zero"), };
//    string strs[10] = {"zero", "one", "two"};
//    cout << strs[1] << endl;
//    for(int i = 0; i < 2; i++) {
//        if(strs[i] == "one") {
//            cout << i << endl;
//        }
//    }
//    string tmp;
//    for(int i = 1; i < 4; i++) {
//        tmp = strs[1].substr(0, i);
//        cout << tmp << endl;
//        for(int j = 0; j < 3; j++) {
//            if(tmp == strs[j]) {
//                cout << "answer tmp = " << tmp << " j = " << j << endl;
//            }
//        }
//    }
//    tmp = "1";
//    int num = (int)(tmp[0]-'0');
//    cout << num << endl;
//    tmp = "TEST";
//    if(tmp[1] == 'E') cout << "okay" << endl;
//
//    vector<vector<string>> bigV;
//    vector<string> smlV;
//    smlV.push_back("firstfirst");
//    smlV.push_back("firstsecond");
//    bigV.push_back(smlV);
//    smlV.clear();
//    smlV.push_back("secondfirst");
//    smlV.push_back("secondsecond");
//    bigV.push_back(smlV);
//    smlV.clear();
//    smlV.assign(bigV[1].begin(), bigV[1].end());
//    for(int i = 0; i < 2; i++) {
//        cout << smlV[i] << endl;
//    }
//    cout << smlV[1][2] << endl;
//
//    return 0;
//}

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string findAns(string x) {
    if(x.length() < 4) return x;
    string ltmp, rtmp;
    int idx = 0;
    for(int i = 0; i < x.length()-2; i++) {
        if(x.substr(i, 3) == "110") {
            ltmp = x.substr(0, i);
            rtmp = x.substr(i+3, x.length()-i-2);
            rtmp = findAns(rtmp);
            if(rtmp[0] == '0') {
                while(rtmp[idx] == '0') idx++;
                if(idx < 0) ltmp += rtmp+"110";
                else ltmp += rtmp.substr(0, idx) + "110" + rtmp.substr(idx, rtmp.length()-idx);
                break;
            } else if(ltmp[i-1] == '1') {
                idx = i-1;
                while(ltmp[idx] == '1') idx--;
                if(idx < 0) ltmp = "110"+ltmp+rtmp;
                else {
                    idx = ltmp.length()-idx-1;
                    ltmp = ltmp.substr(0, idx+1) + "110"
                           + ltmp.substr(idx+1, ltmp.length()-idx-1) + rtmp;
                }
                break;
            }
        }
    }
    if(ltmp.length() != x.length()) return x;
    return ltmp;
}

int main() {
    /*
    string s = "0111111010";
    string tmp = findAns(s);
    while(s != tmp) {
        s = tmp;
        tmp = findAns(tmp);
    }
    cout << tmp << endl;
    */
    char str[40];
    int num = 0;
    int list[100];
    int cnt = 0, i;
    cin.getline(str, 40);
    for (int i = 0; cnt < 40 && str[i]; i++)
    {
        if (str[i] != ' ')
        {
            num = num * 10 + str[i] - '0';
        }
        else
        {
            if (num > 0)
            {
                list[cnt++] = num;
                num = 0;
            }
        }
    }
    for(int i = 0; i < 100 && list[i]; i++) {
        cout << list[i] << ' ' << endl;
    }
    return 0;
}

