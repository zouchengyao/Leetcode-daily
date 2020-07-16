/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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

    void flatten(TreeNode* root)
    {
        if (root == nullptr)    return;
        queue<TreeNode*> v;
        helper(root, v);
        v.pop();    // the first is always the root; 
        auto prev = root;
        while(!v.empty())
        {
            auto curr = v.front();
            v.pop();
            prev -> left = nullptr;
            prev -> right = curr;
            prev = curr;   
        }

    }

    void helper(TreeNode* root, queue<TreeNode*> &v)
    {
        if (root == nullptr)    return;

        v.push(root);
        helper(root->left, v);
        helper(root->right, v);
    }


    vector<TreeNode*> remain;
    void flattenV2(TreeNode* root) {

        if (root == nullptr)    return;

        if (root -> right == nullptr && root->left != nullptr) 
        {
            root->right = root->left;
            root->left = nullptr;
            flatten(root->right);
        }

        if( root->left == nullptr && root->right == nullptr )
        {
            if (remain.size() > 0)
            {
                while(!remain.empty())
                {
                    root -> right = remain.front();
                    remain.erase(remain.begin());
                    root = root->right;
                }
            }
        }

        if (root -> right != nullptr && root->left == nullptr)
            flatten(root->right);

        // else
        if (root->left != nullptr && root->right != nullptr) 
        {
            remain.push_back(root->left);
            root->left = nullptr;
        }

        flatten(root->left);
        flatten(root->right);

    }
};
// @lc code=end

