/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        return constructTree(0, nums.size()-1, nums);        
    }

    TreeNode * constructTree(int left, int right, vector<int>& nums)
    {
        if (left > right)   return nullptr;
        int maxIndex = findMax(nums, left, right);
        auto curr = new TreeNode(nums[maxIndex]);
        
        curr->left = constructTree(left, maxIndex-1, nums);
        curr->right= constructTree(maxIndex+1, right, nums);
        return curr;
    }

    int findMax(vector<int>& nums, int left, int right)
    {
        int maxIndex = 0;
        int maxVal = INT_MIN;
        for (int i = left; i <= right; i++)
        {
            if (nums[i] > maxVal)   
            {
                maxVal = nums[i];   
                maxIndex = i;
            }
        }
        return maxIndex; 
    }
};
// @lc code=end

