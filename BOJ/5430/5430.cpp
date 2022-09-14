#include <bits/stdc++.h>
using namespace std;
int t, n;
string p, arrstr;
deque<int> dq;
bool front = true, error = false;

deque<int> stringToDeque() {
    deque<int> retdq;
    stringstream sstream(arrstr.substr(1, arrstr.size()-2));
    string numstr;
    while(getline(sstream, numstr, ',')) {
        retdq.push_back(stoi(numstr));
    }
    return retdq;
}

string DequeToString() {
    if(dq.empty()) return "[]";
    string retstr = "[";
    if(front) {
        while(!dq.empty()) {
            retstr += to_string(dq.front());
            retstr += ",";
            dq.pop_front();
        }
    } else {
        while(!dq.empty()) {
            retstr += to_string(dq.back());
            retstr += ",";
            dq.pop_back();
        }
    }
    retstr[retstr.size()-1] = ']';
    return retstr;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> p;
        cin >> n;
        cin >> arrstr;
        dq = stringToDeque();
        for(int i = 0; i < p.size(); i++) {
            if(p[i] == 'R') {
                front = !front;
            } else {
                if(dq.empty()) {
                    cout << "error\n";
                    error = true;
                    break;
                }
                if(front) dq.pop_front(); 
                else dq.pop_back();
            }
        }
        if(!error) cout << DequeToString() << '\n';
        front = true;
        error = false;
    }
}