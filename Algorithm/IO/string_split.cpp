#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> split(string str, char delimiter) {
    vector<string> ret;
    stringstream ss(str);
    string tmp;

    while (getline(ss, tmp, delimiter)) { ret.push_back(tmp); }

    return ret;
}

int main() {
    string str;
    getline(cin, str);
    vector<string> res = split(str, ' ');
    return 0;
}