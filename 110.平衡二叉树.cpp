/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isB;
    bool isBalanced(TreeNode* root) {
        isB = true;
        r(root);
        return isB;
    }

    int r(TreeNode* root)
    {
        if (root == nullptr)
            return 0;

        int left = r(root->left) + 1;
        int right = r(root->right) + 1;
        if( abs(left - right) > 1 ) isB = false;
        return max(left, right);
    }
};
// @lc code=end

