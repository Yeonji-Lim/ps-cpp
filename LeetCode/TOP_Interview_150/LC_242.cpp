class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> sm;
        for(int i = 0; i < 26; i++) {
            sm['a'+i] = 0;
        }
        for(char sch: s) {
            sm[sch]++;
        }
        for(char tch: t) {
            if(sm[tch]-- == 0) return false;
        }
        return true;
    }
};