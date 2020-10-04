#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    stack<int> S;
    int temp = 0;
    int ind = 0;
    int val = 2;

    cin >> str;

    for(int i=0; i<str.length() && temp >= 0 && ind >= 0; i++) {
        if(str[i] == '(') temp++;
        else if(str[i] == ')') {
            temp--;
            if(str[i-1] == '[') {
                temp = 1;
                break;
            }
        }
        else if(str[i] == '[') ind++;
        else if(str[i] == ']') {
            ind--;
            if(str[i-1] == '(') {
                ind = 1;
                break;
            }
        }
    }
    if(temp != 0 || ind != 0) {
        printf("0\n");
        return 0;
    }

    for(int i=0; i<str.length(); i++) {
        if(str[i] == '(') S.push(0);
        else if(str[i] == '[') S.push(1);
        else {
            if(str[i] == ')') {
                ind = 0; val = 2;
            } else {
                ind = 1; val = 3;
            }
            while(S.top() != ind) {
                temp += S.top();
                S.pop();
            }
            S.pop();
            temp == 0 ? S.push(val) : S.push(temp * val);
            temp = 0;
        }
    }
    while(!S.empty()) {
        temp += S.top();
        S.pop();
    }
    printf("%d\n", temp);

//    for(int i=0; i<str.length(); i++) {
//        if(str[i] == '(' || str[i] == '[')
//            S.push(str[i]);
//        else if(str[i] == ')'){
//            if(S.top() == '(') {
//                S.pop();
//                S.push('X');
//            } else {
//                while(S.top() != '(') {
//                    if(S.top() == 'X') {
//                        tempS.push('X');tempS.push('X');
//                    } else {
//                        tempS.push('Y');tempS.push('Y');
//                    }
//                    S.pop();
//                }
//                S.pop();
//                while(!tempS.empty()) {
//                    S.push(tempS.top());
//                    tempS.pop();
//                }
//            }
//        }
//        else if(str[i] == ']'){
//            if(S.top() == '[') {
//                S.pop();
//                S.push('Y');
//            } else {
//                while(S.top() != '[') {
//                    if(S.top() == 'X') {
//                        tempS.push('X');tempS.push('X');tempS.push('X');
//                    } else {
//                        tempS.push('Y');tempS.push('Y');tempS.push('Y');
//                    }
//                    S.pop();
//                }
//                S.pop();
//                while(!tempS.empty()) {
//                    S.push(tempS.top());
//                    tempS.pop();
//                }
//            }
//        }
//    }
//    while(!S.empty()) {
//        S.top() == 'X'? result += 2: result += 3;
//        S.pop();
//    }

//    printf("%d\n", result);
    return 0;
}
