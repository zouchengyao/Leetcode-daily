/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // instead of using recursion, we can use the queue for traversal
        // implementing DFS / BFS
        vector<vector<int>> res;
        if (root == nullptr)    return {};
        r(root, res, 0);
        
        for (int i = 0; i < res.size(); i++)
        {
            if ( i % 2 != 0) reverse(res[i].begin(), res[i].end());
        }

        return res;

    }

    void r(TreeNode* root, vector<vector<int>> &v, int level)
    {
        if (root == nullptr)    return;
        // insert current nodes into current level
        if(v.size() <= level)    
            v.push_back({root->val});
        else
        {
            v[level].push_back(root->val);
        }
        r(root->left, v, level+1);
        r(root->right, v, level+1);
    }

};
// @lc code=end

