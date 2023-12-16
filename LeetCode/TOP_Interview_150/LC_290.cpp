#include <sstream>
class Solution {
public:
    vector<string> split(string tar, char del) {
        istringstream iss(tar);
        string buf;
        vector<string> ret;
        while(getline(iss, buf, del)) {
            ret.push_back(buf);
        }
        return ret;
    }

    bool wordPattern(string pattern, string s) {
        vector<string> words = split(s, ' ');
        if(pattern.size() != words.size()) return false;
        unordered_map<char, string> patm;
        unordered_map<string, char> sm;
        for(int i = 0; i < pattern.size(); i++) {
            if(patm.find(pattern[i]) == patm.end()) {
                if(sm.find(words[i]) != sm.end()) return false;
                patm[pattern[i]] = words[i];
                sm[words[i]] = pattern[i];
            } else {
                if(patm[pattern[i]] != words[i]) return false;
            }
        }
        return true;
    }
};