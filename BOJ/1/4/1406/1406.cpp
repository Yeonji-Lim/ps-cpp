#include <bits/stdc++.h>
using namespace std;
int m, cur;
string str;
list<char> content;
auto iter = content.begin();

void printStr() {
    for(iter = content.begin(); iter != content.end(); iter++) {
        cout << *iter;
    }
}

void L() {
    if(cur > 0) cur--;
}

void D() {
    if(cur < content.size()) cur++;
}

void B() {
    if(cur > 0) {
        iter = content.begin();
        for(int i = 0; i < cur-1; i++) {
            iter++;
        }
        content.erase(iter);
        cur--;
    }
}

void P(char apd) {
    iter = content.begin();
    for(int i = 0; i < cur; i++) {
        iter++;
    }
    content.insert(iter, apd);
    cur++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> str >> m;
    cin.ignore();
    cur = str.length();
    for(int i = 0; i < cur; i++) {
        content.push_back(str[i]);
    }
    for(int i = 0; i < m; i++) {
        getline(cin, str);
        switch(str[0]) {
            case 'L':
                L(); break;
            case 'D':
                D(); break;
            case 'B':
                B(); break;
            case 'P':
                P(str[2]); break;
        }
    }
    printStr();
}