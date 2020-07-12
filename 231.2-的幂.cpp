/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
    if (n <= 0) return false;   
    // cout << (n & (n-1)) << endl;
    return ( (n&(n-1)) == 0);


    // if (n < 0) return false;
    // std::string binary = std::bitset<32>(n).to_string(); //to binary
    // int count = 0;
    // for (const auto & c : binary)
    //     if (c == '1') count++;
    
    // // cout << binary << endl;
    // return count==1;
    }
};
// @lc code=end

