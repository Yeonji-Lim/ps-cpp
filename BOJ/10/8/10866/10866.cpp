#include <bits/stdc++.h>
#define MXS 10001
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string cmd;
    int num, dq[MXS], h = MXS/2, t = MXS/2;
    while(n--) {
        cin >> cmd;
        if(cmd == "push_front") {
            cin >> num;
            dq[--h] = num;
        } else if(cmd == "push_back") {
            cin >> num;
            dq[t++] = num;
        } else if(cmd == "pop_front") {
            if(t-h == 0) cout << "-1\n";
            else cout << dq[h++] << '\n';
        } else if(cmd == "pop_back") {
            if(t-h == 0) cout << "-1\n";
            else cout << dq[--t] << '\n';
        } else if(cmd == "size") {
            cout << t-h << '\n';
        } else if(cmd == "empty") {
            if(t-h == 0) cout << "1\n";
            else cout << "0\n";
        } else if(cmd == "front") {
            if(t-h == 0) cout << "-1\n";
            else cout << dq[h] << '\n';
        } else if(cmd == "back") {
            if(t-h == 0) cout << "-1\n";
            else cout << dq[t-1] << '\n';
        }
    }
}