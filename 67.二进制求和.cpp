/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {

        string res;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());    // reverse for better processing

        int carry = 0;
        int n = max(a.size(), b.size());
        for ( int i = 0; i < n; i++ )
        {
            carry += i < a.size() ? ( a.at(i) == '1') : 0;
            carry += i < b.size() ? ( b.at(i) == '1') : 0;
            res.push_back( (carry % 2) ? '1' : '0' );
            carry /= 2; 
        }

        if (carry)  res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

