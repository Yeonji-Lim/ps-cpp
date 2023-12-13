class Solution {
public:
    vector<string> split(string tar, char d) {
        istringstream iss(tar);
        string buf;
        vector<string> ret;
        while(getline(iss, buf, d)) {
            ret.push_back(buf);
        }
        return ret;
    }
    int lengthOfLastWord(string s) {
        vector<string> words = split(s, ' ');
        while(words.back().length() == 0) words.pop_back();
        return words.back().length();
    }
};