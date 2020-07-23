/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr)    return {};
        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);
        while(!q.empty())
        {
            auto size = q.size();
            int maxVal = INT_MIN;
            while(size--)
            {
                auto curr = q.front();      q.pop();
                maxVal = maxVal > curr->val ? maxVal : curr->val;
                if(curr->left!=nullptr)     q.push(curr->left);
                if(curr->right!=nullptr)    q.push(curr->right);    
            }
        res.push_back(maxVal);
        }
        return res;
    }
};
// @lc code=end

