/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        // a modified level-order traversal
        if (root == nullptr)    return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto curr = q.front();      q.pop();
                // cout << "Node: " << curr->val << ", size is " <<size<< endl;
                if (curr->left!=nullptr)    q.push(curr->left);
                if (curr->right!=nullptr)   q.push(curr->right);

                if (size == 0)              res.push_back(curr->val);
            }
        }

        return res;

    }
};
// @lc code=end

