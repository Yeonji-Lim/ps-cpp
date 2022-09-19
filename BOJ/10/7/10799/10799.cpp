#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    stack<char> st;
    int curiron = 0, ans = 0;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            curiron++;
            st.push(str[i]);
        } else {
            if(!st.empty() && st.top() == '(') {
                st.pop();
                curiron--;
                st.push('*');
                ans += curiron;
            } else {
                st.push(str[i]);
                curiron--;
                ans++;
            }
        }
    }
    cout << ans << '\n';
}

/**
 * @brief 
 * ( 다음에 )가 오면 바로 * 처리
 * 앞에 (가 나온 개수를 따로 세기
 * 레이저가 아닌 )가 오면 개수 --
 */ 