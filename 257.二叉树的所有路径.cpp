/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        r(root, {});
        return res;
    }

    void r(TreeNode * root, string s)
    {
        if (root == nullptr)    return;
        if ( root -> left == nullptr && root -> right == nullptr )
        {
            // this is the leaf node
            if(s.size() != 0)   res.push_back( s + "->"+ to_string(root->val));
            else                res.push_back(to_string(root->val)); 
            return;
        }
        // cout << s.size() << endl;
        if(s.size() != 0) (s = s + "->" + to_string(root->val));
        else            s = to_string(root->val);
        r(root->left, s);
        r(root->right, s);
    }
 
};
// @lc code=end

