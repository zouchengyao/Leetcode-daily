/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        if (root==nullptr)  return 0;
        return r(root, 1);
    }

    int r(TreeNode* root, int level)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            return level;
        }
        int ls = INT_MAX, rs = INT_MAX;
        if(root->left != nullptr) ls = r(root->left, level+1);
        if(root->right != nullptr) rs = r(root->right, level+1);
        return min(ls, rs);
    }

            // this is the best recursion 
            int minDepthV2(TreeNode* root)
            {
                // 为nullptr 返回的是 0
                if (root == nullptr)
                    return 0;
                int leftDepth = minDepth(root->left);
                int rightDepth = minDepth(root->right);
                // 处理只有左子树或者右子树的情况或者叶子节点
                if (root->left == nullptr || root->right == nullptr)
                    return leftDepth + rightDepth + 1;

                // 同时存在左右子树
                return 1 + min(leftDepth, rightDepth);
            }

};
// @lc code=end

