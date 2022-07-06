#include <bits/stdc++.h>
using namespace std;
stack<int> st;

int main() {
    int n, tmp;
    cin >> n;
    string cmd;
    for(int i = 0; i < n; i++) {
        cin >> cmd;
        if(cmd == "push") {
            cin >> tmp;
            st.push(tmp);
        } else if(cmd == "top") {
            if(st.empty()) {
                cout << -1 << endl;
                continue;
            }
            cout << st.top() << endl;
        } else if(cmd == "pop") {
            if(st.empty()) {
                cout << -1 << endl;
                continue;
            }
            cout << st.top() << endl;
            st.pop();
        } else if(cmd == "size") {
            cout << st.size() << endl;
        } else if(cmd == "empty") {
            if(st.empty()) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}