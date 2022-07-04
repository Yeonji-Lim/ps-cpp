#include <bits/stdc++.h>
#include <string>
#define NUM_MAX 1000000000
using namespace std;
string str;
vector<string> cmds;
int n, num;

int stringToInt(string tar) {
    int ans = 0;
    for(int i = 0; i < tar.length(); i++) {
        ans *= 10;
        ans += tar[i]-'0';
    }
    return ans;
}

bool cmdNum(stack<int> &st, string tar) {
    st.push(stringToInt(tar));
    return true;
}

bool cmdPop(stack<int> &st) {
    if(st.empty()) return false;
    st.pop();
    return true;
}

bool cmdInv(stack<int> &st) {
    if(st.empty()) return false;
    int i = st.top();
    st.pop();
    st.push(i*-1);
    return true;
}

bool cmdDup(stack<int> &st) {
    if(st.empty()) return false;
    int i = st.top();
    st.push(i);
    return true;
}

bool cmdSwp(stack<int> &st) {
    if(st.empty()) return false;
    int i = st.top();
    st.pop();
    if(st.empty()) return false;
    int j = st.top();
    st.pop();
    st.push(i);
    st.push(j);
    return true;
}

bool cmdAdd(stack<int> &st) {
    long long chk;
    if(st.empty()) return false;
    int i = st.top();
    st.pop();
    if(st.empty()) return false;
    int j = st.top();
    st.pop();
    chk = i+j;
    if(chk > NUM_MAX || chk < NUM_MAX * -1) {
        st.push(j);
        st.push(i);
        return false;
    }
    st.push(i+j);
    return true;
}

bool cmdSub(stack<int> &st) {
    long long chk;
    if(st.empty()) return false;
    int i = st.top();
    st.pop();
    if(st.empty()) return false;
    int j = st.top();
    st.pop();
    chk = j-i;
    if(chk > NUM_MAX || chk < NUM_MAX * -1) {
        st.push(j);
        st.push(i);
        return false;
    }
    st.push(j-i);
    return true;
}

bool cmdMul(stack<int> &st) {
    long long chk;
    if(st.empty()) return false;
    int i = st.top();
    st.pop();
    if(st.empty()) return false;
    int j = st.top();
    st.pop();
    chk = i*j;
    if(chk > NUM_MAX || chk < NUM_MAX * -1) {
        st.push(j);
        st.push(i);
        return false;
    }
    st.push(i*j);
    return true;
}

bool cmdDiv(stack<int> &st) {
    if(st.empty()) return false;
    int i = st.top();
    if(i == 0) return false;
    st.pop();
    if(st.empty()) return false;
    int j = st.top();
    st.pop();
    st.push(j/i);
    return true;
}

bool cmdMod(stack<int> &st) {
    if(st.empty()) return false;
    int i = st.top();
    if(i == 0) return false;
    st.pop();
    if(st.empty()) return false;
    int j = st.top();
    st.pop();
    st.push(j%i);
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while(1) {
        cin >> str;
        if(str == "QUIT") return 0;
        while(str != "END") {
            cmds.push_back(str);
            cin >> str;
        }
        cin >> n;

        vector<bool> error(n, false);
        vector<stack<int>> sts;
        for(int i = 0; i < n; i++) {
            cin >> num;
            stack<int> st;
            st.push(num);
            sts.push_back(st);
        }

        for(int i = 0; i < (int)cmds.size(); i++) {
            str = cmds[i];
            if(str == "NUM") {                    
                i++;
                for(int j = 0; j < (int)sts.size(); j++) {
                    if(error[j]) continue;
                    if(!cmdNum(sts[j], cmds[i]) || sts[j].empty()) error[j] = true;
                }
            } else if(str == "POP") {
                for(int j = 0; j < (int)sts.size(); j++) {
                    if(error[j]) continue;
                    if(!cmdPop(sts[j]) || sts[j].empty()) error[j] = true;
                }
            } else if(str == "INV") {
                for(int j = 0; j < (int)sts.size(); j++) {
                    if(error[j]) continue;
                    if(!cmdInv(sts[j]) || sts[j].empty()) error[j] = true;
                }
            } else if(str == "DUP") {
                for(int j = 0; j < (int)sts.size(); j++) {
                    if(error[j]) continue;
                    if(!cmdDup(sts[j]) || sts[j].empty()) error[j] = true;
                }
            } else if(str == "SWP") {
                for(int j = 0; j < (int)sts.size(); j++) {
                    if(error[j]) continue;
                    if(!cmdSwp(sts[j]) || sts[j].empty()) error[j] = true;
                }
            } else if(str == "ADD") {
                for(int j = 0; j < (int)sts.size(); j++) {
                    if(error[j]) continue;
                    if(!cmdAdd(sts[j]) || sts[j].empty()) error[j] = true;
                }
            } else if(str == "SUB") {
                for(int j = 0; j < (int)sts.size(); j++) {
                    if(error[j]) continue;
                    if(!cmdSub(sts[j]) || sts[j].empty()) error[j] = true;
                }
            } else if(str == "MUL") {
                for(int j = 0; j < (int)sts.size(); j++) {
                    if(error[j]) continue;
                    if(!cmdMul(sts[j]) || sts[j].empty()) error[j] = true;
                }
            } else if(str == "DIV") {
                for(int j = 0; j < (int)sts.size(); j++) {
                    if(error[j]) continue;
                    if(!cmdDiv(sts[j]) || sts[j].empty()) error[j] = true;
                }
            } else if(str == "MOD") {
                for(int j = 0; j < (int)sts.size(); j++) {
                    if(error[j]) continue;
                    if(!cmdMod(sts[j]) || sts[j].empty()) error[j] = true;
                }
            }
        }

        for(int i = 0; i < sts.size(); i++) {
            if(sts[i].size() != 1 || error[i]) {
                cout << "ERROR" << endl;
                continue;
            }
            while(!sts[i].empty()) {
                cout << sts[i].top() << endl;
                sts[i].pop();
            }
        }
        cout << endl;
    }
    return 0;
}