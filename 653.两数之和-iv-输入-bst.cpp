/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
    bool findTarget(TreeNode* root, int k) {
        set<int> s;
        return readTree(s, root, k) ;
    }
    
    bool readTree( set<int> &s, TreeNode* root, int k )
    {
        if (root == nullptr)    return false;
        if (s.find(root->val) != s.end())   return true;
        s.insert(k - root->val);
        return readTree(s, root->left, k) || readTree(s, root->right, k);
    }

};
// @lc code=end

