/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
    int findTilt(TreeNode* root) {
        // base case
        int sum = 0;
        findSum(root, sum);
        return sum;
    }

    int findSum(TreeNode* root, int& sum)
    {
        if (root == nullptr)    return 0;

        auto left = findSum(root->left, sum );
        auto right= findSum(root->right, sum);
        auto curr = abs(left - right);
        sum += curr;        
        return root->val + left + right;
    }

};
// @lc code=end

