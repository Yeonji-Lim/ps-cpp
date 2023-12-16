class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2) return false;
        stack<char> st;
        for(char sch : s) {
            if(sch=='(' || sch=='[' || sch=='{') {
                st.push(sch);
            } else {
                if(st.empty()) return false; 
                char tch = st.top();
                switch(sch) {
                    case ')' :
                        if(tch != '(') return false;
                        break;
                    case ']' :
                        if(tch != '[') return false;
                        break;
                    case '}' :
                        if(tch != '{') return false;
                        break;
                }
                st.pop();
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};