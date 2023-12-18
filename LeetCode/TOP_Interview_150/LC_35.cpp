class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1, m;
        if(nums[e] < target) {
            return nums.size();
        }
        while(s<=e) {
            m = (s+e)/2;
            if(nums[m] == target) return m;
            if(nums[m] < target) s = m+1;
            else e = m-1;
        }
        return s;
    }
};