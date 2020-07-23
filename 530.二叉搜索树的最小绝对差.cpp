/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    vector<int> v;
    int getMinimumDifference(TreeNode* root) {
        calcmin(root);
        // sort(v.begin(), v.end());
        int minVal = INT_MAX;
        for(int i = 0; i < v.size()-1;i++ )
        {
            minVal = minVal < (v[i+1]-v[i]) ? minVal : (v[i+1]-v[i]);
        }
        return minVal;
    }

    void calcmin(TreeNode* root)
    {
        if (root == nullptr)    return;
        calcmin(root->left);
        v.push_back(root->val);
        calcmin(root->right);
    }

};
// @lc code=end

