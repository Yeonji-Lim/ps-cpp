class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for(int i = 0; i < 26; i++) {
            m['a'+i] = 0;
        }
        for(char mch: magazine) {
            m[mch]++;
        }
        for(char rch: ransomNote) {
            if(m[rch] > 0) m[rch]--;
            else return false;
        }
        return true;
    }
};