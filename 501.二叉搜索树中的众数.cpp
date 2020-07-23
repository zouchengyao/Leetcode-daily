/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    unordered_map<int, int> m;
    vector<int> findMode(TreeNode* root) {
        find(root);
        int maxVal = INT_MIN;
        vector<int> res;


        for (const auto & p : m)
        {
            // cout << p.first << ":" << p.second << endl;
            if (maxVal == p.second)
            {
                res.push_back(p.first);
            }
            else if (maxVal < p.second)
            {
                res.clear();
                maxVal = p.second;
                res.push_back(p.first);
            }
        }
        return res;
    }

    void find( TreeNode* root )
    {
        if ( root == nullptr )  return;
        find(root->left);
        m[root->val] ++;
        find(root->right);

    }

};
// @lc code=end

