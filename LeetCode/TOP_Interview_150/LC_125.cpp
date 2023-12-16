class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                t += s[i]-'A'+'a';
            } else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
                t += s[i];
            }
        }
        int mid = t.size()/2;
        reverse(t.begin(), t.begin()+mid);
        if(2*mid == t.size()) {
            if(t.substr(0, mid) == t.substr(mid, mid)) return true;
            return false;
        } else {
            if(t.substr(0, mid) == t.substr(mid+1, mid)) return true;
            return false;
        }
    }
};