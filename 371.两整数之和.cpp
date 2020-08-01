/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        // bit-wise calculate
        // int last_bit = 0, carry = 0;

        // XOR is the good way of calculating 
        if ( (a&b)==0)    return a ^ b;
        else 
            return getSum(a ^ b, ((unsigned int )(a & b) )<< 1 ); 

    }
};
// @lc code=end

