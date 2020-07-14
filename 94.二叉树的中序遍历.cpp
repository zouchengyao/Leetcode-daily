/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        // r(root);
        vector<int> res;
        stack<TreeNode*> s;
        auto curr = root;
        
        while(curr != nullptr || !s.empty() )
        {
            // crambing as much left ptr as possible
            while(curr != nullptr)
            {
                s.push(curr);
                curr = curr -> left;
            }
            curr = s.top();
            s.pop();
            res.push_back(curr->val);
            curr = curr -> right;

        }
        return res;
    }

    // void r(TreeNode* root)
    // {
    //     if (root == NULL)   return;
    //     r(root->left);

    //     res.push_back(root->val);

    //     r(root->right);

    // }

};
// @lc code=end

