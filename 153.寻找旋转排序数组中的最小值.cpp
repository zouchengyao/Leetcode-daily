/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:

    int findMin(vector<int>& nums)
    {
        int left = 0, right = nums.size() - 1;
        if (nums[0] < nums[right])  return nums[0];
        if (nums.size() == 1)   return nums[0];

        while( left <= right )
        {
            int mid = left + (right - left) / 2;
            if (nums[0] <= nums[mid])       // mid could be the same as 0
                left = mid + 1;
            else 
                right = mid - 1;
        }

        return min( nums[left], nums[right] );

    }


    int findMin1(vector<int>& nums) {
        // 
        int left = 0, right = nums.size();
        // 
        if (nums[0] < nums[right-1])   return nums[0];        
        if (nums.size() == 1)   return nums[0];

        // to find a particular pattern in a seq, use left < right
        while(left < right)
        {
            int mid = left + (right-left) / 2;
            // cout << left << ":" << right << endl;
            cout << nums[0] << " vs " << nums[mid] << endl;
            if (nums[0] <= nums[mid] )
                left = mid + 1;
            else if ( nums[0] > nums[mid])
                right = mid;
        }
        
        return nums[left];


    }
};
// @lc code=end

