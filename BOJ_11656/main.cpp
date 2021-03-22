/* 2021.3.22 Solved - 2576KB 4ms */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
    return a < b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int i;
    vector<string> v;
    string tmp;
    cin >> tmp;
    for(i = 0; tmp[i] != '\0'; i++) {
        v.push_back(tmp.substr(i));
    }
    sort(v.begin(), v.end(), compare);
    for(i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }
    return 0;
}