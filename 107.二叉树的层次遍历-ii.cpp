/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> v;
        r(root, 0, v);
        reverse(v.begin(), v.end());
        return v;
    }

    void r(TreeNode* root, int level, vector<vector<int>> &v )
    {
        if (root == nullptr)    return;

        if(v.size() <= level)
            v.push_back({root->val});
        else
            v.at(level).push_back(root->val);
        
        r(root->left, level+1, v);
        r(root->right, level+1, v);
    }

};
// @lc code=end

