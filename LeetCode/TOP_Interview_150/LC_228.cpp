class Solution {
public:
    void addNewNum(stack<int>& st, vector<string>& ans) {
        if(st.size() == 1) {
            ans.push_back(to_string(st.top()));
            st.pop();
        } else {
            string str = to_string(st.top());
            st.pop();
            str = to_string(st.top()) + "->" + str;
            ans.push_back(str);
            st.pop();
        }
    }
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        stack<int> st;
        vector<string> ans;
        st.push(nums[0]);
        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[i-1]+1) {
                addNewNum(st, ans);
                st.push(nums[i]);
            } else {
                if(st.size() == 2) {
                    st.pop();
                }
                st.push(nums[i]);
            }
        }
        addNewNum(st, ans);
        return ans;
    }
};