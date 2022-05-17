#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
string str;

bool isGroupWord() {
    vector<char> v;
    char prev = str[0];
    v.push_back(str[0]);
    for(int i = 1; i < str.length(); i++) {
        if(str[i-1] != str[i]) {
            for(int j = 0; j < v.size(); j++)
                if(v[j] == str[i])
                    return false;
            v.push_back(str[i]);
        }
    }
    return true;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        if(isGroupWord()) ans++;
    }
    cout << ans << endl;
    return 0;
}