#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    string word;
    while(n--) {
        cin >> word;
        stack<char> st;
        for(int i = 0; i < word.length(); i++) {
            if(!st.empty() && word[i] == st.top()) st.pop();
            else st.push(word[i]);
        }
        if(st.empty()) ans++;
    }
    cout << ans << '\n';
}