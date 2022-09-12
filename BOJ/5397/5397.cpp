#include <iostream>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    string str;
    list<char> pwd = {};
    auto iter = pwd.begin();
    cin >> t;
    while(t--) {
        cin >> str;
        for(int i = 0; i < str.length(); i++) {
            switch(str[i]) {
                case '<':
                    if(iter != pwd.begin()) iter--;
                    break;
                case '>':
                    if(iter != pwd.end()) iter++;
                    break;
                case '-':
                    if(iter != pwd.begin()) {
                        iter--;
                        iter = pwd.erase(iter);
                    }
                    break;
                default:
                    pwd.insert(iter, str[i]);
                    break;
            }
        }
        for(iter = pwd.begin(); iter != pwd.end();) {
            cout << *iter;
            iter = pwd.erase(iter);
        }
        iter = pwd.begin();
        cout << '\n';
    }
    return 0;
}