/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> v;
        q.push(root);
        double average;
        while(!q.empty())
        {

            int size = q.size();
            int diviend = q.size();
            while(size--)
            {
                auto curr = q.front();
                q.pop();
                average += curr->val;
                if (curr->left)     q.push(curr->left);
                if (curr->right)    q.push(curr->right);
            }
            // cout << average << ":" << diviend << endl;
            v.push_back(average/diviend);
            average = 0.0;
        }


        return v;
    }
};
// @lc code=end

