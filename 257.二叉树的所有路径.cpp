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
        vector<vector<int>> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        for (const auto c : res)
            for(const auto a : c)
            {
                cout << a << endl;
            }


        return {};
    }

    void r(TreeNode* root, vector<int> v)
    {
        if (root == nullptr)    return;
        v.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr )
        {
            // this is the leaf
            res.push_back(v);
            return;
        }
        r(root->left, v);
        r(root->right, v);

        return;

    }

};
// @lc code=end

