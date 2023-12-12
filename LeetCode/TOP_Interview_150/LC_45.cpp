class Solution {
    vector<int> dp;
    vector<int> ns;
public:
    int getmin(int i) {
        if(dp[i] != -1) return dp[i];
        dp[i] = 10000;
        for(int j = i+1; j <= i+ns[i] && j < ns.size(); j++) {
            dp[i] = min(dp[i], getmin(j)+1);
        }
        return dp[i];
    }

    int jump(vector<int>& nums) {
        ns = nums;
        if(ns.size() == 1) return 0;
        dp.assign(ns.size(), -1);
        dp[ns.size()-1] = 0;
        dp[0] = 10000;
        for(int i = 1; i <= ns[0] && i < ns.size(); i++) {
            dp[0] = min(dp[0], getmin(i)+1);
        }
        return dp[0];
    }
};