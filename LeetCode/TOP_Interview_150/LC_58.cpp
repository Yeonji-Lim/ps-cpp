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

/*faster*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret = 0;
        bool flag = false;
        for(int i = s.length()-1; i > -1; i--) {
            if(s[i] != ' ') {
                ret++;
                flag = true;
            } else if(flag) {
                break;
            }
        }
        return ret;
    }
};