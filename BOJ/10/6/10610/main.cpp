/* 2021.5.27 Solved - 2408KB 4ms */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string n;
    vector<char> v;
    int sum = 0;
    bool ten = false;
    cin >> n;
    for(int i = 0; i < n.length(); i++) {
        v.push_back(n[i]);
        sum += n[i]-'0';
        if(!ten && n[i] == '0') ten = true;
    }
    if(sum%3 != 0 || !ten) {
        cout << "-1\n";
        return 0;
    }
    sort(v.begin(), v.end());
    for(int i = v.size()-1; i > -1; i--) {
        cout << v[i];
    }
    cout << "\n";
    return 0;
}
