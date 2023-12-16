class Solution {
public:
    bool isSubsequence(string s, string t) {
        int si = 0;
        for(int ti = 0; ti < t.size() && si < s.size(); ti++){
            if(t[ti] == s[si]) si++;
        }
        if(si == s.size()) return true;
        return false;
    }
};