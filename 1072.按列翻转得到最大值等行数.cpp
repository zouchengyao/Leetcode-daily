/*
 * @lc app=leetcode.cn id=1072 lang=cpp
 *
 * [1072] 按列翻转得到最大值等行数
 */

// @lc code=start
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map< string, int> m;
        int maxVal = INT_MIN;
        for (auto & row : matrix)
        {
            string s;        
            if (row[0] == 0)
            {
                for (auto & d : row)
                {
                    d = (d == 0) ? 1 : 0;
                    s += d + '0';
                }
            }

            else
            {
                for (const auto & d : row)
                    s += d + '0';
            }
            m[s] ++;
            maxVal = max( maxVal, m[s] );


        }

        return maxVal;
    }
};
// @lc code=end

