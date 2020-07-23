/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode* root) {
        // bfs traversal
        queue<TreeNode*> q;
        q.push(root);
        long long res;
        while(!q.empty())
        {
            res = __LONG_MAX__ ;
            int size = q.size();
            while(size--)
            {
                // level order 
                auto curr = q.front();   q.pop();
                if (res == __LONG_MAX__ ) res = curr->val;
                if (curr ->left != nullptr )    q.push(curr->left);
                if (curr->right != nullptr )    q.push(curr->right);
            }
        }
        return res;
    }
};
// @lc code=end

