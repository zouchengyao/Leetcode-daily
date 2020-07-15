/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        return compareTree(root, root);
    }

    bool compareTree(TreeNode* left_root, TreeNode* right_root)
    {
        if ( left_root == nullptr || right_root == nullptr)
        {
            if (left_root == right_root)    // if both of them are nullptr
                return true;
            else 
                return false;
        }
        if (left_root -> val != right_root -> val)  return false;
        return compareTree(left_root -> left, right_root -> right) && compareTree(left_root -> right, right_root -> left);
    }



    void r(TreeNode* root, vector<int> &v)
    {
        if (root == nullptr)    return;

        r(root->left, v);
        v.push_back(root->val);
        r(root->right, v);
    }
};
// @lc code=end

