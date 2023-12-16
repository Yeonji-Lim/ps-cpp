class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> chm1;
        unordered_map<char, char> chm2;
        for(int i = 0; i < s.size(); i++) {
            if(chm1.find(s[i])!=chm1.end()) {
                if(chm1[s[i]] != t[i]) return false;
            } else {
                if(chm2.find(t[i]) != chm2.end()) return false;
                chm1[s[i]] = t[i];
                chm2[t[i]] = s[i];
            }
        }
        return true;
    }
};