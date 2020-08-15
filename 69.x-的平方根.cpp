/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            
            if ( (long long ) mid * mid == x )
                return mid;
            else if ((long long) mid * mid < x)
                left = mid + 1;
            else   
                right = mid -1;
        }
        // cout << left << ":"<< right << endl;
        return right;

    }
};
// @lc code=end

