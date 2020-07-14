/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return r(p, q);
    }

    bool r(TreeNode* p, TreeNode* q)
    {
        if ( p == nullptr || q == nullptr)
        {
            if ( p == nullptr && q == nullptr)
                return true;
            else
                return false;
        }
        if (p->val != q->val)   return false;

        return r(p->left, q->left) && r(p->right, q->right);

    }


};
// @lc code=end

