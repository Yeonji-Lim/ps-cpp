#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0;
    int cnt = 0;
    stack<char> S;
    string str;
    cin >> str;
    for(int i=0; i<str.length(); i++) {
        if(S.empty() || str[i] == '(') {
            S.push(str[i]);
            cnt++;
        }
        else {
            cnt--;
            if(S.top() == '(') {
                S.pop();
                S.push('*');
                ans += cnt;
            } else {
                S.push(')');
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
