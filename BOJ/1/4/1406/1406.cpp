#include <iostream>
#include <list>
using namespace std;
int m, cur;
string str;
list<char> content;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> str >> m;
    cin.ignore();
    cur = str.length();
    for(int i = 0; i < cur; i++) {
        content.push_back(str[i]);
    }
    auto iter = content.end();
    for(int i = 0; i < m; i++) {
        getline(cin, str);
        switch(str[0]) {
            case 'L':
                if(iter != content.begin()) 
                iter--;
                break;
            case 'D':
                if(iter != content.end()) 
                iter++;
                break;
            case 'B':
                if(iter != content.begin()) {
                	auto tmpiter = iter;
                	tmpiter--;
                    content.erase(tmpiter);
                }
                break;
            case 'P':
                content.insert(iter, str[2]);
                break;
        }
    }
    for(iter = content.begin(); iter != content.end(); iter++) {
        cout << *iter;
    }
}
