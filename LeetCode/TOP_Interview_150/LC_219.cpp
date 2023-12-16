class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> nm;
        for(int i = 0; i < nums.size(); i++) {
            if(nm.find(nums[i]) != nm.end() && abs(nm[nums[i]]-i) <= k) return true;
            nm[nums[i]] = i;
        }
        return false;
    }
};