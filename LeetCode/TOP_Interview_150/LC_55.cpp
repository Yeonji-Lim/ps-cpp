class Solution {
    vector<int> dp;
    vector<int> ns;
public:
    bool isPos(int i) {
        if(dp[i] != -1) return dp[i];
        dp[i] = 0;
        for(int j = i+1; j <= i+ns[i]; j++) {
            if(isPos(j)) {
                dp[i] = 1;
                break;
            }
        }
        return dp[i];
    }

    bool canJump(vector<int>& nums) {
        ns = nums;
        dp.assign(nums.size(), -1);
        dp[nums.size()-1] = 1;
        for(int i = 0; i <= nums[0]; i++) {
            if(isPos(i)) return true;
        }
        return false;
    }
};

/*Faster*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxl = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i > maxl) return false;
            maxl = max(maxl, i+nums[i]);
        }
        return true;
    }
};