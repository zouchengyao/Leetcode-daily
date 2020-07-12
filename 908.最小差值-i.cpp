/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 */

// @lc code=start
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        if (A.size() < 2 ) return 0;
        int minVal = INT_MAX, maxVal = INT_MIN; 
        for (auto & c : A)
        {
            if ( c > maxVal) maxVal = c;
            if ( c < minVal) minVal = c;
        }
        int res = (maxVal - K) - (minVal + K);
        if (res < 0 )   res = 0;
        return res;
    }
};
// @lc code=end

