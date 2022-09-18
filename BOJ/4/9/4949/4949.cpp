#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    getline(cin, str);
    while(str != ".") {
        stack<char> st;
        for(int i = 0; i < str.length(); i++) {
            if (str[i] == '[' || str[i] == '(') {
                st.push(str[i]);
            } else if (str[i] == ']') {
                if(!st.empty() && st.top() == '[') st.pop();
                else {
                    st.push(str[i]);
                    break;
                }
            } else if (str[i] == ')') {
                if(!st.empty() && st.top() == '(') st.pop();
                else {
                    st.push(str[i]);
                    break;
                }
            }
        }
        if(st.empty()) cout << "yes\n";
        else cout << "no\n";
        getline(cin, str);
    }
}