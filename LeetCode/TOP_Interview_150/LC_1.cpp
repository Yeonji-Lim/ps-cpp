class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nm; // 남은 수, 인덱스
        for(int i = 0; i < nums.size(); i++) {
            if(nm.find(nums[i]) != nm.end()) {
                return {nm[nums[i]], i};
            }
            nm[target-nums[i]] = i;
        }
        return {};
    }
};