/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, TreeNode*> m;
    void recoverTree(TreeNode* root) {
        if (root == nullptr)    return;
        recoverTree(root->left);
        if ( root -> val < prev -> val)
        {
            s = (s == NULL) ?  prev : s;
            t = root;
        }
        prev = root;
        recoverTree(root->right);
    }

    void help(TreeNode* root, vector<int> &v)
    {
        if (root == nullptr)    return;

        help(root->left, v);
        v.push_back(root->val);
        m[root->val] = root;
        help(root->right, v);
    }

    vector<int> find(vector<int> &v)
    {
        int len = v.size();
        int x = -1, y = -1;
        for (int i = 0; i < v.size()-1; i++)
        {
            if (v[i+1] < v[i] )
            {
                y = v[i+1];
                if ( x==-1) x = v[i];
                else break;
            }
        }
        return {x, y}; 
    }

};
// @lc code=end

       