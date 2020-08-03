/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while(!q.empty())
        {
            auto size = q.size();
            cout << "---------" << endl;
            
            while(size--)
            {
                auto curr = q.front();
                cout << q.front()->val << endl;
                q.pop();
                
                if (curr -> left) q.push(curr->left);
                if (curr ->right) q.push(curr->right);

            }


            level++;

            
        }


        return root;
    }
};
// @lc code=end

