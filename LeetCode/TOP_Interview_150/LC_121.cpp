class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_p = INT_MAX, ret = 0, today_r = 0;
        for(int p : prices) {
            if(p < min_p) {
                min_p = p;
            }
            today_r = p-min_p;
            if(today_r > ret) {
                ret = today_r;
            }
        }
        return ret;
    }
};
