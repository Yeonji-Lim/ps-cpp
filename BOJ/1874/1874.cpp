#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> st;
    vector<char> answer;
    int n, nxtnum = 1, target;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> target;
        if( !st.empty() && st.top() >= target) {
            bool find = false;
            while(!st.empty() && st.top() != target) {
                st.pop();
                answer.push_back('-');
            }
            if(!st.empty() && st.top() == target) find = true;
            if(!find) {
                cout << "NO\n";
                return 0;
            }
            answer.push_back('-');
            st.pop();
        } else {
            if(nxtnum > target) {
                cout << "NO\n";
                return 0;
            }
            while(nxtnum != target) {
                st.push(nxtnum);
                answer.push_back('+');
                nxtnum++;
            }
            answer.push_back('+');
            answer.push_back('-');
            nxtnum++;
        }
    }
    for(int i = 0; i < (int) answer.size(); i++) {
        cout << answer[i] <<'\n';
    }
}

/**
 * 안되는 경우
 * 스택이 비어있는 경우
 * 
 * 두 개의 저장
 * 다음에 넣을 숫자를 알려주는 거
 * 
 * 숫자가 스택에 있으면 가능 -> 스택의 탑이 지금 숫자보다 큼
 * 그런데 pop하다가 작은 숫자를 만나거나 엠티가 되면 불가능임
 * 
 * 숫자가 스택에 없다 + 다음에 넣을 숫자가 지금 뽑을 숫자보다 크다면 불가능
 */