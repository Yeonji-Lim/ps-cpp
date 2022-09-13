#include <bits/stdc++.h>
#define MXS 10005
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string cmd;
    int num, q[MXS], head = 0, tail = 0;
    while(n--) {
        cin >> cmd;
        if(cmd == "push") {
            cin >> num;
            q[tail++] = num;
        } else if(cmd == "pop") {
            if(head-tail == 0) cout << "-1\n";
            else cout << q[head++] << '\n';
        } else if(cmd == "size") {
            cout << tail-head << '\n';
        } else if(cmd == "empty") {
            if(head-tail == 0) cout << "1\n";
            else cout << "0\n";
        } else if(cmd == "front") {
            if(head-tail == 0) cout << "-1\n";
            else cout << q[head] << '\n';
        } else if(cmd == "back") {
            if(head-tail == 0) cout << "-1\n";
            else cout << q[tail-1] << '\n';
        }
    }
}