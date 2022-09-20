#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0, tmp;
    string str;
    cin >> str;
    stack<char> cst;
    stack<int> ist;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(' || str[i] == '[') {
            cst.push(str[i]);
        } else {
            if(str[i] == ')') {
                if(cst.empty()) {
                    cout << "0\n";
                    return 0;
                }
                if(cst.top() == '[') {
                    cout << "0\n";
                    return 0;
                }
                if(cst.top() == '*') {
                    tmp = 0;
                    while(cst.top() != '(') {
                        if(cst.top() == '[') {
                            cout << "0\n";
                            return 0;
                        }
                        cst.pop();
                        tmp += ist.top();
                        ist.pop();
                    }
                    ist.push(tmp*2);
                } else {
                    ist.push(2);
                }
                cst.pop();
                cst.push('*');
            } else {
                if(cst.empty()) {
                    cout << "0\n";
                    return 0;
                }
                if(cst.top() == '(') {
                    cout << "0\n";
                    return 0;
                }
                if(cst.top() == '*') {
                    tmp = 0;
                    while(cst.top() != '[') {
                        if(cst.top() == '(') {
                            cout << "0\n";
                            return 0;
                        }
                        cst.pop();
                        tmp += ist.top();
                        ist.pop();
                    }
                    ist.push(tmp*3);
                } else {
                    ist.push(3);
                }
                cst.pop();
                cst.push('*');
            }
        }
    }
    while(!ist.empty()) {
        ans += ist.top();
        ist.pop();
    }
    cout << ans << '\n';
}

/**
 * @brief 
 * () 2
 * [] 3
 * (X) 2*X
 * [X] 3*X
 * XY X+Y
 * ) ] -> 숫자 스택에서 뽑아서 곱하기 연산
 * () [] -> 2, 3을 스택에 추가
 * ( [ -> 
 * 유효하지 않으면 0 출력
 * 
 * 값이 들어가는 스택과 문자가 들어가는 스택을 따로?
 * 
 */