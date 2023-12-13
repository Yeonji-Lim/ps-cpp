class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = strs[0];
        int n = strs[0].size();
        for(int i = 1; i < strs.size(); i++) {
            int nn = min((int)strs[i].size(),n); 
            for(int j = 0; j < nn; j++) {
                if(ret[j] != strs[i][j]) {
                    ret = ret.substr(0, j);
                    if(ret.size() == 0) return "";
                    break;
                }
            }
            if(ret.size() > nn) {
                ret = ret.substr(0, nn);
            }
        }
        return ret;
    }
};