#include <bits/stdc++.h>
using namespace std;
queue<int> q;

int main() {
    int n, tmp; 
    cin >> n;
    string cmd;
    for(int i = 0; i < n; i++) {
        cin >> cmd;
        if(cmd == "push") {
            cin >> tmp;
            q.push(tmp);
        } else if(cmd == "pop") {
            if(q.empty()){
                cout << -1 << endl;
            } else {
                cout << q.front() << endl;
                q.pop();
            }
        } else if(cmd == "front") {
            if(q.empty()){
                cout << -1 << endl;
            } else {
                cout << q.front() << endl;
            }
        } else if(cmd == "back") {
            if(q.empty()) {
                cout << -1 << endl;
            } else {
                cout << q.back() << endl;
            }
        } else if (cmd == "size") {
            cout << q.size() << endl;
        } else if (cmd == "empty") {
            if(q.empty()) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}