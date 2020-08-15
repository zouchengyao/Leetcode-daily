/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;   // no profit
        int minPurchase = prices[0];
        long int maxProfit = INT_MIN;
        for(const auto & p : prices)
        {
            maxProfit = maxProfit < p - minPurchase ? p - minPurchase : maxProfit;
            minPurchase = p < minPurchase ? p : minPurchase;
        } 
        return maxProfit;
    }
};
// @lc code=end

