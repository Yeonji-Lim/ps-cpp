class Solution {
public:
    map<string, string> m = {
        {"CM", "DCCCC"},
        {"CD", "CCCC"},
        {"XC", "LXXXX"},
        {"XL", "XXXX"},
        {"IX", "VIIII"},
        {"IV", "IIII"}
    };
    map<char, int> cal = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int romanToInt(string s) {
        int ans = 0, i;
        string str = "";
        for(i = 0; i < s.length()-1; i++) {
            auto iter = m.find(s.substr(i, 2));
            if(iter != m.end()) {
                str += iter->second;
                i++;
            } else {
                str += s[i];
                if(i == s.length()-2) {
                    str += s[++i];
                }
            }
        }
        if(i == s.length()-1) str += s[s.length()-1];
        for(i = 0; i < str.length(); i++) {
            ans += cal.find(str[i])->second;
        }
        return ans;
    }
};