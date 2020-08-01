/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        if (n < 1)  return 0;

        int left = 0, right = n;
        
        while(left <= right)
        {
            auto mid = left + (right - left) / 2;
            auto ret = guess(mid);
            switch (ret)
            {
            case 1:
                left = mid + 1;
                break;
            case -1:
                right = mid - 1;    
                break;
            case 0:
                return mid;
                break;
            }
        }
    return -1;
    }
};
// @lc code=end

