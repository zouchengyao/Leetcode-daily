/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)   return 0;
        if (nums[0] > nums[1])  return 0;
        if (nums[nums.size()-1] > nums[nums.size()-2])  return nums.size()-1;

        int left = 1, right = nums.size() -2;

        while(left <= right)
        {
            int mid = left + (right-left) / 2;
            if ( nums[mid -1] < nums[mid] && nums[mid] > nums[mid + 1] )
            {
                // result found
                return mid;
            }            

            else if (  nums[mid - 1 ] > nums[mid] && nums[mid] > nums[mid + 1]  )
            {
                // peak should be the left
                right = mid - 1;
            }
            else
            {
                // peak in the right
                left = mid + 1;
            }
        }

        // if ( nums[left] > nums[right] ) return right;
        // else 
            return left;

    }
};
// @lc code=end

