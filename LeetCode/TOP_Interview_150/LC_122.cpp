class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp = prices[0], maxp = prices[0], ret = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < prices[i-1]) {
                ret += maxp-minp;
                minp = prices[i];
                maxp = prices[i];
            } else if (prices[i] > prices[i-1]) {
                maxp = prices[i];
            }
        }
        ret += maxp-minp;
        return ret;
    }
};