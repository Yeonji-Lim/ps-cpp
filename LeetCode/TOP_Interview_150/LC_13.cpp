class Solution {
public:
    map<string, int> m = {
        {"CM", 900},
        {"CD", 400},
        {"XC", 90},
        {"XL", 40},
        {"IX", 9},
        {"IV", 4}
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
                ans += iter->second;
                i++;
            } else {
                ans += cal.find(s[i])->second;
                if(i == s.length()-2) {
                    ans += cal.find(s[++i])->second;
                }
            }
        }
        if(i == s.length()-1) 
            ans += cal.find(s[s.length()-1])->second;
        return ans;
    }
};

/*faster*/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(m[s[i]] < m[s[i+1]]) {
                ans -= m[s[i]];
            } else {
                ans += m[s[i]];
            }
        }
        return ans;
    }
};