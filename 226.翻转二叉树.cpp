/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    TreeNode* invertTree(TreeNode* root) {
        f(root);
        return root;
    }

    void f(TreeNode* root)
    {
        if( root == nullptr )   return;

        swap(root->left, root->right);

        f(root -> left);
        f(root-> right);

    }
};
// @lc code=end

