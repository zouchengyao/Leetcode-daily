/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {

        // using dp to solve this problem
        vector<int> dp(n+1, 0);
        dp[0] = 1;        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                // j is the chosen root node [node 1 to node n] for divide/conquer
                // dp[j-1] means the left side's number of combinations
                // dp[i-j] means the right side's number of combinations
                // every one can be the root, with the different left number & right number
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};
// @lc code=end

