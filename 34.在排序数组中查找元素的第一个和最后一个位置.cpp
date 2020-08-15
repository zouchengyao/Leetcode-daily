/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
private:
    int target;

public:


    vector<int> searchRange(vector<int>& nums, int target)
    {   
        // two binary search with boundaries
        int left = 0, right = nums.size() - 1;
        // left boundary search 
        // * * * * [ * * * 
        // we will push the right gradually until it is smaller than left
        while( left <= right )  // closed boundary
        {
            int mid = left + (right - left) / 2;
            if ( nums[mid] == target )  
                right = mid - 1;
            else if (nums[mid] < target )
                left  = mid + 1;
            else 
                right = mid - 1;
        }
        if (left >= nums.size() || nums[left] != target)
            return {-1, -1};
        int l = left;

        left = 0;
        right = nums.size() - 1;
        // right boundary search
        // for == condition, we will push the left until it is greater than right
        while( left <= right )
        {
            int mid = left + (right - left ) / 2;
            if (nums[mid] == target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid -1;
            else
                left = mid + 1;
        }

        if ( right < 0 || nums[right] != target )
            return {-1, -1};
        int r = right;

        return {l, r};

    }





    vector<int> searchRange1(vector<int>& nums, int target) {
        
        auto len = nums.size();
        int left = 0, right = len -1;
        if (len == 0)   return {-1, -1};

        // first, we will try to find the left index
        while(left < right)
        {
            auto mid = left + (right - left ) / 2;
            if (nums[mid] >= target)
                right = mid;
            else   
                left = mid + 1;
        }
        // after this, left & right should be the same
        if (nums[left] != target)   return {-1, -1};
        int start = left;
        // so, we will do it again
        left = 0;
        right = len -1;

        while( left < right)
        {
            auto mid = left + 1 + (right - left ) / 2;
            if (nums[mid] <= target)
                left = mid;
            else
                right = mid - 1;
        }        

        if (nums[left] != target)  return {-1, -1};
        int end = right;


        return {start, end};

    }

    int search( int start, int end, vector<int> & nums )
    {
        auto mid = start + ( end - start ) / 2;
        if (start > end )  return -1;

        if ( nums[mid] == target )
            return mid;

        if ( nums[mid] < target )
            return search( mid + 1, end, nums );
        else
            return search( start, mid -1 , nums);
    }


};
// @lc code=end

