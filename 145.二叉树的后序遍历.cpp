/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        return recursion(root);
    }

    vector<int> recursion( TreeNode* root )
    {
        if (root == nullptr )   return {};
        
        vector<int> v;
        auto l = recursion(root->left);
        auto r = recursion(root->right);

        v.insert(v.end(), l.begin(), l.end());
        v.insert(v.end(), r.begin(), r.end());
        v.push_back(root->val);
        return v;
    }

};
// @lc code=end

