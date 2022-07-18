#include <bits/stdc++.h>
#define MAXVAL 1000000000
using namespace std;
string cmd;
int n;
long long num, num2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> cmd;
    while(cmd != "QUIT") {
        vector<string> cmds;
        queue<int> nums;
        while(cmd != "END") {
            if(cmd == "NUM") {
                cin >> num;
                nums.push(num);
            }
            cmds.push_back(cmd);
            cin >> cmd;
        }

        cin >> n;
        vector<stack<int>> sts;
        for(int i = 0; i < n; i++) {
            stack<int> st;
            cin >> num;
            st.push(num);
            sts.push_back(st);
        }

        for(auto && cmd : cmds) {
            if(cmd == "NUM") {
                num = nums.front();
                nums.pop();
                if(num < 0 || num > MAXVAL) {
                    for(auto && st : sts) { st.push(MAXVAL+1); }
                    break; // 완전 종료
                }
                for(auto && st : sts) { 
                    if(!st.empty() && st.top() == MAXVAL+1) continue;
                    st.push(num); 
                }
            } else if(cmd == "POP") {
                for(auto && st : sts) {                   
                    if(st.empty()) st.push(MAXVAL+1);
                    if(st.top() == MAXVAL+1) continue;
                    st.pop();
                }
            } else if(cmd == "INV") {
                for(auto && st : sts) {                    
                    if(st.empty()) st.push(MAXVAL+1);
                    if(st.top() == MAXVAL+1) continue;
                    num = st.top();
                    st.pop();
                    st.push(-num);
                }
            } else if(cmd == "DUP") {
                for(auto && st : sts) {                    
                    if(st.empty()) st.push(MAXVAL+1);
                    if(st.top() == MAXVAL+1) continue;
                    num = st.top();
                    st.push(num);   
                }
            } else if(cmd == "SWP") {
                for(auto && st : sts) {                    
                    if(st.size() < 2) st.push(MAXVAL+1);
                    if(st.top() == MAXVAL+1) continue;

                    num = st.top();
                    st.pop();
                    num2 = st.top();
                    st.pop();
                    st.push(num2);
                    st.push(num);   
                }
            } else  {
                for(auto && st : sts) {
                    if(st.size() < 2) st.push(MAXVAL+1);
                    if(st.top() == MAXVAL+1) continue;

                    num = st.top();
                    st.pop();
                    num2 = st.top();
                    st.pop();
                    if(cmd == "ADD") {
                        num2 += num;
                    } else if(cmd == "SUB") {
                        num2 -= num;
                    } else if(cmd == "MUL") {
                        num2 *= num;
                    } else if(cmd == "DIV") {
                        if(num == 0) {
                            st.push(MAXVAL+1);
                        } else {
                            bool minus = false;
                            if(num < 0 || num2 < 0) minus = true;
                            num2 /= num;
                            if(num2 > 0) num *= -1;
                        }
                    } else if(cmd == "MOD") {
                        if(num == 0) {
                            st.push(MAXVAL+1);
                        } else {
                            bool minus = false;
                            if(num < 0) minus = true;
                            num2 %= num;
                            if(num2 > 0) num *= -1;
                        }
                    }
                    if(!st.empty() && st.top() == MAXVAL+1) continue;
                    if(num2 > MAXVAL || num2 < -MAXVAL) st.push(MAXVAL+1);
                    else st.push(num2);
                    
                }
            }
        }

        for(auto && st : sts) {
            if(st.size() != 1 || st.top() == MAXVAL+1) cout << "ERROR\n";
            else cout << (int)st.top() << '\n';
        }
        cout << '\n';
        cin >> cmd;
    }
    return 0;
}