#include <bits/stdc++.h>
using namespace std;

string [8] crotia = {"c=", "c-", "dzw=", "d-", "lj", "nj", "s=", "z="}
int main() {
    int ans = 0;
    string str; 
    cin >> str; 
    for(int i = 0; i<str.length()-2; i++) {
        for(int j = 0; j < crotia.size(); j++) {
            if (str.sub(i, crotia[j].length()) == crotia[j]) {
                ans++;
                i += crotia[j].length();
            }
        }
    }
    cout << ans << endl;
}